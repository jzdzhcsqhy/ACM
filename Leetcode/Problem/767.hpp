#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		string str;
		while( cin>> str)
		{
			cout << reorganizeString(str) << endl;
		}
		return true;
	}

public:
	string reorganizeString(string S) {
		map<char, int > mapTemp;
		for( char ch : S )
		{
			mapTemp[ch] ++;
		}

		string strTemp;

		int iCompare = S.length() / 2;
		if( S.length() %2 )
		{
			iCompare = S.length() / 2 + 1;
		}
		vector<string> vctRs;
		for( auto m : mapTemp )
		{
			if( m.second > iCompare)
			{
				return "";
			}
			vctRs.push_back(string(m.second, m.first));
		}

		sort(vctRs.begin(), vctRs.end(), [&](string l, string r)->bool
		{
			return l.length() > r.length();
		});

		for( auto s : vctRs )
		{
			strTemp += s;
		}

		string strRs(S.length(), ' ');

		int iIndex = 0;
		for( size_t i=0; i< strRs.length(); i+= 2 )
		{
			strRs[i] = strTemp[iIndex++];
		}
		for( size_t i=1; i< strRs.length(); i+=2 )
		{
			strRs[i] = strTemp[iIndex++];
		}
		return strRs;
	}

};


CSolutionBase* gpBase = new Solution;