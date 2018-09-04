#pragma once
#include "../Base.hpp"

class Solution : public CSolutionBase
{

public:
	bool run()
	{
		int n;
		while( cin >> n )
		{
			cout << lastRemaining(n) << endl;
		}

		//for( int i=1; i< 10000; i++ )
		//{
		//	int iCnt = log(i) / log(2);
		//	cout << i << ": " << lastRemaining(i) << endl;
		//}
		return true;
	}

public:
	/*int lastRemaining(int n) {

		if( 1 == n )
		{
			return 1;
		}
		int iCnt = log(n) / log(2);

		std::vector<int > vctRt;
		std::vector<int > vctTemp;
		for( size_t i=2; i<=n; i+=2 )
		{
			vctRt.push_back(i);
		}

		for( int i=1; i< iCnt; i++  )
		{
			vctTemp = vctRt;
			vctRt.clear();
			if( i%2 )
			{
				for( size_t j=vctTemp.size() -2 ; j>=0 && j< vctTemp.size(); j-=2 )
				{
					vctRt.insert(vctRt.begin(), vctTemp[j]);
				}
			}
			else
			{
				for( size_t j=1; j< vctTemp.size(); j+=2 )
				{
					vctRt.push_back(vctTemp[j]);
				}
			}
		}


		return vctRt[0];
	}*/

	int GetValue(int n, bool bRight)
	{
		if (1 == n)
		{
			return 1;
		}
		if(2 == n )
		{
			if( bRight  )
			{
				return 1;
			}
			else
			{
				return 2;
			}

		}

		if(bRight)
		{
			if( n % 2 )
			{
				return 2 * (GetValue(n / 2, !bRight));
			}
			else
			{
				return 2 * (GetValue(n / 2, !bRight)) -1;
			}
		}
		else
		{
			return 2 * (GetValue(n / 2, !bRight));
		}

	}

	int lastRemaining(int n) {
		return GetValue(n, false);
	}
};


CSolutionBase* gpBase = new Solution;