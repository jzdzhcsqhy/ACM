#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		vector<int> vct = { 1,12,-5,-6,50,3 };
		cout << findMaxAverage(vct, 4);
		return true;
	}

public:
	double findMaxAverage(vector<int>& nums, int k) {
		int iSum = 0;
		for( size_t i=0; i< k; i++ )
		{
			iSum += nums[i];
		}

		int iLeft = 0;
		for(size_t i = k; i< nums.size(); i++ )
		{
			iLeft += (nums[i] - nums[i-k]);
			if( iLeft > 0 )
			{
				iSum += iLeft;
				iLeft = 0;
			}
		}
		return  1.0*iSum / k;
	}

};


CSolutionBase* gpBase = new Solution;