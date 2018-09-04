#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		std::vector<int > nums = { 1, 1,1 };
		cout << subarraySum(nums, 2 )<< endl;
		return true;
	}

public:

	int subarraySum(vector<int>& nums, int k) 
	{
		int iRs = 0;
		for( size_t i=0; i< nums.size(); i++ )
		{
			int iSum = 0;
			for( size_t j=i; j<nums.size(); j++ )
			{
				iSum += nums[j];
				if( k == iSum )
				{
					iRs++;
				}
			}
		}

		return iRs;
	}

};


CSolutionBase* gpBase = new Solution;