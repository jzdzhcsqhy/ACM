#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		vector<int> v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
		cout << trap(v) << endl;
		return true;
	}

public:
	int trap(vector<int>& height) {
		if( !height.size() )
		{
			return 0;
		}
		int iSum = 0;

		std::vector<int> vctLeftMax = height;
		std::vector<int> vctRightMax = height;

		int iLeftMax = height[0];
		int iRightMax = height[height.size() - 1];

		for( size_t i=0; i<height.size(); i++ )
		{
			vctLeftMax[i] = iLeftMax;
			if( height[i] > iLeftMax )
			{
				iLeftMax = height[i];
			}
		}
		for( size_t i = height.size()-1; i>=0&& i<height.size(); i-- )
		{
			vctRightMax[i] = iRightMax;
			if( iRightMax < height[i] )
			{
				iRightMax = height[i];
			}
		}

		for(size_t i=0; i< height.size(); i++ ) 
		{
			int iLeft = min(vctLeftMax[i], vctRightMax[i]);
			if( iLeft > height[i] )
			{
				iSum += iLeft - height[i];
			}
		}

		return iSum;
	}
};


CSolutionBase* gpBase = new Solution;	