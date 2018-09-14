#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		string A = "abcde";
		string B = "cdeab";

		while( cin>> A >> B)
		{
			cout << rotateString(A, B) << endl;
		}
		
		return true;
	}

public:
	bool rotateString(string A, string B) {
		if( A.size() != B.size() )
		{
			return false;
		}
		A += A;
		return -1 != A.find(B);
	}

};


CSolutionBase* gpBase = new Solution;