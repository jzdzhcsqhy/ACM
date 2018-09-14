#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		vector<vector<int> > matrix =
		{
			{1,3,5},{6,7,12},{11,14,14}
		};
		cout << kthSmallest(matrix, 3) << endl;
		return true;
	}

public:
	int kthSmallest(vector<vector<int> >& matrix, int k) {
		if (!matrix.size())
		{
			return 0;
		}
		priority_queue<int, vector<int>, greater<int> > q;
		int iMax = ceil(sqrt(k));
		for (size_t i = 0; i < matrix.size(); i++)
		{
			int iMargin = matrix[i].size();
			if( i >= iMax )
			{
				iMargin = iMax;
			}
			for (size_t j = 0; j < iMargin; j++)
			{
				q.push(matrix[i][j]);
			}
		}
		int rs = -1;
		while (k--)
		{
			rs = q.top();
			q.pop();
		}
		return rs;
	}

};


CSolutionBase* gpBase = new Solution;