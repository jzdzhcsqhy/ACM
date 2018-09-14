#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		string str;
		int k;
		while( cin >> str >> k)
		{
			cout << decodeAtIndex(str, k) << endl;
		}
		return true;
	}

public:
	string decodeAtIndex(string S, int K) {
		string strRs;

		int iLen = 0;
		int i = 0;
		for( i=0; i< S.length(); i++ )
		{
			char c = S[i];
			if( isdigit(c) )
			{
				iLen *= c - '0';
			}
			else
			{
				iLen++;
			}
			if( iLen >= K )
			{
				break;
			}
		}


		return strRs;
	}
};


CSolutionBase* gpBase = new Solution;