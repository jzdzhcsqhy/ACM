#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{

		string str = "Let's take LeetCode contest";
		cout << reverseWords(str) << endl;
		return true;
	}

public:
	string reverseWords(string s) {
		stringstream ss(s);
		string strSub = "";
		const char ccSpliter = ' ';
		
		string strRs = "";
		while (std::getline(ss, strSub, ccSpliter))
		{
			if (strSub.empty())
			{
				continue;
			}
			if( !strRs.empty() )
			{
				strRs += " ";
			}
			

			strRs.append(strSub.rbegin(), strSub.rend());
		}
		return strRs;
	}

};


CSolutionBase* gpBase = new Solution;