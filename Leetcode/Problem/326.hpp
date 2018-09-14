#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		int i;
		while( cin >> i )
		{
			cout << isPowerOfThree(i) << endl;
		}
		return true;
	}

public:
	bool isPowerOfThree(int n) {
		int iMax = pow(3, floor(log(INT_MAX) / log(3)));

		if (iMax%n)
		{
			return false;
		}
		return true;
	}

};


CSolutionBase* gpBase = new Solution;