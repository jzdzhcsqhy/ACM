/*
				   _ooOoo_
				  o8888888o
				  88" . "88
				  (| -_- |)
				  O\  =  /O
			   ____/`---'\____
			 .'  \\|     |//  `.
			/  \\|||  :  |||//  \
		   /  _||||| -:- |||||-  \
		   |   | \\\  -  /// |   |
		   | \_|  ''\---/''  |   |
		   \  .-\__  `-`  ___/-. /
		 ___`. .'  /--.--\  `. . __
	  ."" '<  `.___\_<|>_/___.'  >'"".
	 | | :  `- \`.;`\ _ /`;.`/ - ` : | |
	 \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
				   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		 I have a dream!A AC deram!!
 orz orz orz orz orz orz orz orz orz orz orz
 orz orz orz orz orz orz orz orz orz orz orz
 orz orz orz orz orz orz orz orz orz orz orz

*/

#pragma once
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>
#include <sstream>
#include <tuple>
#include <math.h>
#include <list>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class CSolutionBase
{
public:
	virtual bool run() = 0;TA < һ is 
	//���ݴ����vector�ṹ����һ�ö�������
	//vector������ı�����һ�����������������Ҫȱʧĳ���ӽڵ㣬��-1���
	// vct �Ǵ���Ľڵ���Ϣ
	// iIndex �ǵ�ǰ�ڵ����ڵ����������ݹ�ʹ��
	TreeNode* InitTree(vector<int> & vct, int iIndex)
	{
		if (iIndex >= (int)vct.size() || vct[iIndex] == -1)
		{
			return nullptr;
		}

		TreeNode* pNode = new TreeNode(vct[iIndex]);

		pNode->left = InitTree(vct, iIndex * 2 + 1);
		pNode->right = InitTree(vct, iIndex * 2 + 2);

		return pNode;
		

	}
};