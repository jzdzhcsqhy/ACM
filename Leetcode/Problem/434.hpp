#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		cout << countSegments("       ") << endl;
		return true;
	}



public:
	int countSegments(string s){
		trim(s);
		if( !s.length() )
		{
			return 0;
		}

		s.erase(unique(s.begin(), s.end()),s.end());
		

		int iCnt = 0;
		for( auto ch : s )
		{
			if( ch == ' ' )
			{
				iCnt++;
			}
		}

		return iCnt + 1;
	}

	void trim(string& str)
	{
		string::size_type pos = str.find_last_not_of(' ');
		if (pos != string::npos)
		{
			str.erase(pos + 1);
			pos = str.find_first_not_of(' ');
			if (pos != string::npos) str.erase(0, pos);
		}
		else str.erase(str.begin(), str.end());
	}

};


CSolutionBase* gpBase = new Solution;