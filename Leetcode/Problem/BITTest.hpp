#pragma once
#include "../Base.hpp"

#include "../Points/BinaryIndexTree.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		std::vector<int> vctIn = {1,2,3,4,5,6,7,8,9,10};
		CBinaryIndexTree<int> oTree(vctIn);


		oTree.add(3, 20);

		int i, j;
		while( cin>> i >> j )
		{
			cout << oTree.GetSum(i, j) << endl;
		}
		

		return true;
	}

public:
	string reorganizeString(string S)
	{

	}

};


CSolutionBase* gpBase = new Solution;