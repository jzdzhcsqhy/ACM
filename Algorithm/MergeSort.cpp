#include <iostream>

using namespace std;


void Merge(int a[100], int l, int r )
{
	int b[100],c[100];
}
void MergeSort(int a[100], int l, int r)
{
	if( r <= l )
	{
		return ;
	}
	MergeSort(a,l, (l+r)/2);
	MergeSort(a,(l+r)/+1, r);
	Merge(a, l, r);
}



int main( int argc, char** argv )
{
	int a[100];
	int n;
	while( cin >>  n)
	{
		int t = n;
		while( t -- )
		{
			cin >> a[t];
		}

		MergeSort(a,0,n-1);
		output(a,n);
	}

	return 0;
}