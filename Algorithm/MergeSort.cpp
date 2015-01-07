#include <iostream>

using namespace std;

void output( int a[100], int n);

void Merge(int a[100], int l, int r )
{
	int b[100];
	int mid = (l+r)/2+1;
	int i=l;
	int j=mid;
	int k=l;

	memset(b, 0, sizeof(b));
	memcpy(b, a, sizeof(b));

	while( i<mid || j <=r )
	{
		if( i >= mid )
		{
			while(j <= r )
			{
				a[k++] = b[j++];
			}
			break;
		}
		else if( j> r)
		{
			while( i < mid )
			{
				a[k++] = b[i++];
			}
			break;
		}
		else
		{
			a[k++] = b[i]>b[j]?b[j++]:b[i++];
		}
	}
}
void MergeSort(int a[100], int l, int r)
{
	if( r <= l )
	{
		return ;
	}
	MergeSort(a,l, (l+r)/2);
	MergeSort(a,(l+r)/2+1, r);
	Merge(a, l, r);
}

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