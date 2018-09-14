#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		vector<int> vct = { 0,1,0,1,0,1,9 };
		cout << singleNumber(vct) << endl;
		return true;
	}

public:
	int singleNumber(vector<int>& nums) {
		// algorithm copy from network ,
		// NOT MINE  !!!!
		
		int iRs = 0;

		// declare variable 
		int one = 0;
		int two = 0;
		int three = 0;


		// here 
		for( auto i : nums )
		{
				
		}

		return iRs;
	}

};


CSolutionBase* gpBase = new Solution;