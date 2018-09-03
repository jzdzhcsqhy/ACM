#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		double x;
		int n;
		while (cin >> x >> n)
		{
			cout << myPow(x, n) << endl;
		}
		
		
		return true;
	}

public:
	double calculate(double x, int n)
	{
		if (0 == n)
		{
			return 1;
		}
		if (1 == n)
		{
			return x;
		}
		int nNext = n / 2;

		double dNextRs = calculate(x, nNext);

		if (n % 2)
		{
			return dNextRs*dNextRs *x;
		}
		else
		{
			return dNextRs * dNextRs;
		}
	}
	double myPow(double x, int n) {
		int t = n;
		if (n < 0)
		{
			t = -n;
		}

		double dRs = calculate(x, t);
		if (n > 0)
		{
			return dRs;
		}
		else
		{
			return 1 / dRs;
		}
	}

};


CSolutionBase* gpBase = new Solution;