#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		std::vector<int > vctTree = {1, 2, 2, 3,-1, -1, 3};

		auto pRoot = InitTree(vctTree, 0);
		cout << isSymmetric(pRoot) << endl;
		return true;
	}

public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
		{
			return true;
		}

		int iDepth = getDepth(root);

		vector<vector<TreeNode*> > vctTemp(iDepth, vector<TreeNode*>() );

		vctTemp[0].push_back(root);


		for( size_t i=0; i< vctTemp.size()-1; i++ )
		{
			for( size_t j=0; j< vctTemp[i].size(); j++ )
			{
				TreeNode* pNode = vctTemp[i][j];
				if( pNode )
				{
					vctTemp[i + 1].push_back(pNode->left);
					vctTemp[i + 1].push_back(pNode->right);
				}
			}
		}

		for( size_t i=0; i< vctTemp.size() ;i++ )
		{
			size_t l = 0;
			size_t r = vctTemp[i].size() - 1;
			while( l< r)
			{
				auto pl = vctTemp[i][l];
				auto pr = vctTemp[i][r];

				if( (pl && !pr) || (!pl &&pr) )
				{
					return false;
				}
				else if( !pl && !pr )
				{
					l++;
					r--;
					continue;
				}
				else if(pl->val != pr->val )
				{
					return false;
				}

				l++;
				r--;
			}
		}

		return true;
	}

	int getDepth( TreeNode* root )
	{
		if( !root )
		{
			return 0;
		}

		return max(getDepth(root->left), getDepth(root->right)) + 1;
	}
};


CSolutionBase* gpBase = new Solution;