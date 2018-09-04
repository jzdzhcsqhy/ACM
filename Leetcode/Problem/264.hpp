#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		int i;
		while( cin>> i )
		{
			cout << nthUglyNumber(i) << endl;
		}
		return true;
	}

public:
	int nthUglyNumber(int n) {
		std::vector<int > vct = { 1 };

		std::map<int, bool > mapTemp;
		mapTemp[1] = true;

		auto funcCheck = [&](int iValue, int iBase )-> void
		{
			if(iValue <= INT_MAX/iBase && !mapTemp[iValue*iBase] )
			{
				mapTemp[iValue * iBase] = true;
				vct.push_back(iValue* iBase);
			}
		};

		for( size_t i=0; i< vct.size(); i++ )
		{
			funcCheck(vct[i], 2);
			funcCheck(vct[i], 3);
			funcCheck(vct[i], 5);
		}

		sort(vct.begin(), vct.end());
		return vct[n -1];
	}

};


CSolutionBase* gpBase = new Solution;