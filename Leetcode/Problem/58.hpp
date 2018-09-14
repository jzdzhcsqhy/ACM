#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		string s;
		while( cin >> s )
		{
			s = "hello world";
			cout << lengthOfLastWord(s) << endl;
		}
		return true;
	}

public:

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

	int lengthOfLastWord(string s) {

		trim(s);
		if( s.empty() )
		{
			return 0;
		}

		int iCnt = 0;
		for( size_t i = s.size() -1; i>=0 && i< s.length(); i-- )
		{
			if( s[i] == ' ' )
			{
				break;
			}
			iCnt++;
		}
		return iCnt;
	}

};


CSolutionBase* gpBase = new Solution;