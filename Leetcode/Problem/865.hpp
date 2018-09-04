#pragma once
#include "../Base.hpp"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution : public CSolutionBase
{

public:

	TreeNode* InitTree( vector<int> & vct, int iIndex )
	{
		if( iIndex >= vct.size() || vct[iIndex] == -1)
		{
			return nullptr;
		}

		TreeNode* pNode = new TreeNode(vct[iIndex]);
	
		pNode->left = InitTree(vct, iIndex * 2 +1);
		pNode->right = InitTree(vct, iIndex * 2 + 2);

		return pNode;

	}


	bool run()
	{
		vector<int> vct = { 3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4 };
		
		TreeNode* pRoot = InitTree(vct, 0);

		TreeNode* pRs = subtreeWithAllDeepest(pRoot);
		return true;
	}

public:
	map<TreeNode*, TreeNode* > m_mapParent;
	map<int, std::vector<TreeNode*> > m_mapDepth;

	void DFS(TreeNode* root, int iDepth)
	{
		m_mapDepth[iDepth].push_back(root);
		if (root->left)
		{
			m_mapParent[root->left] = root;
			DFS(root->left, iDepth + 1);
		}
		if (root->right)
		{
			m_mapParent[root->right] = root;
			DFS(root->right, iDepth + 1);
		}
	}

	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		m_mapParent.clear();
		DFS(root, 1);

		auto mit = m_mapDepth.rbegin();
		if (mit == m_mapDepth.rend())
		{
			return nullptr;
		}

		std::vector<TreeNode*> vctRs = mit->second;

		while (vctRs.size() > 1)
		{
			std::vector<TreeNode* > vctTemp;
			for (auto pNode : vctRs)
			{
				if (m_mapParent[pNode] != nullptr )
				{
					vctTemp.push_back(m_mapParent[pNode]);
				}
			}
			sort(vctTemp.begin(), vctTemp.end());
			vctTemp.erase(unique(vctTemp.begin(), vctTemp.end()),vctTemp.end());
			vctRs = vctTemp;
		}

		return vctRs[0];
	}

};


CSolutionBase* gpBase = new Solution;