#include <iostream>
#include "sort.h"

using namespace std;

void output(int a[100], int n)
{
	for(int i=0; i<=n; i++ )
	{
		cout << a[i] << " " ;
	}
	cout << endl;
}

int main( int argc, char** argv )
{
	int a[100];
	int n;
	while( cin >>  n)
	{
		int t = n-1;
		while( t >=0 )
		{
			cin >> a[t--];
		}
		//output(a,n-1);
		MergeSort(a,0,n-1);
		output(a,n-1);
	}
	system("pause");
	return 0;
}