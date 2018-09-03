#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		std::vector<int> vctIn;
		vctIn.push_back(5);
		vctIn.push_back(2);
		vctIn.push_back(3);
		vctIn.push_back(1);

		cout << maximumProduct(vctIn) <<endl;

		return true;
	}

public:
	int maximumProduct(vector<int>& nums) 
	{
		int iMax = INT_MIN;

		sort(nums.begin(), nums.end(), [&](int l, int r)->bool
		{
			return l > r;
		});


		int iLen = nums.size();
		
		if (nums[0] < 0)
		{
			return nums[iLen -1] * nums[iLen - 2] * nums[iLen - 3];
		}
		else if( nums[iLen-1] > 0 )
		{
			return nums[0] * nums[1] * nums[2];
		}
		else
		{
			int front = nums[0] * nums[1] * nums[2];
			int back = nums[0] * nums[iLen - 1] * nums[iLen - 2];
			return front > back ? front : back;
		}
	}

};


CSolutionBase* gpBase = new Solution;