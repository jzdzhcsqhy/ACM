#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		int n;
		while( cin>> n)
		{
			cout << isPowerOfFour(n) << endl;
		}
		return true;
	}

public:
	bool isPowerOfFour(int num) {
		auto funcCheck = [](int n, int bit)->bool
		{
			if (n ^ (0x01 << bit))
			{
				return false;
			}
			else
			{
				return true;
			}
		};

		if( funcCheck(num,0) ||
			funcCheck(num,2) ||
			funcCheck(num,4) ||
			funcCheck(num,6) ||
			funcCheck(num,8) ||
			funcCheck(num,10) ||
			funcCheck(num,12) ||
			funcCheck(num,14) ||
			funcCheck(num,16) ||
			funcCheck(num,18) ||
			funcCheck(num,20) ||
			funcCheck(num,22) ||
			funcCheck(num,24) ||
			funcCheck(num,26) ||
			funcCheck(num,28) ||
			funcCheck(num,30) 
			)
		{
			return true;
		}
		return false;
	}

};


CSolutionBase* gpBase = new Solution;