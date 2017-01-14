#include "iostream"
#include <queue>
#include <map>
#include <vector>
using namespace std;

typedef struct 
{	
	int x;
	int y;
}Step;



bool mark[4][4];

int main( int argc, char** argv )
{

	char ch;
	memset(mark, 0, sizeof(mark) );
	
	int i,j,k;
	queue<Step> q;
	
	for( i=0; i<4; i++ )
	{
		for( j=0; j<4; j++ )
		{
			ch = getchar();
			if('+' == ch  )
			{
				mark[i][j] = !mark[i][j];
				for( int k=0; k<4; k++ )
				{
					mark[i][k] = !mark[i][k];  
					mark[k][j] = ! mark[k][j]; 
				}
			}
		}
		getchar();
	}

	for( i=0; i<4; i++ )
	{
		for( j=0; j<4; j++ )
		{
			if( mark[i][j])
			{
				Step tmp;
				tmp.x = i+1;
				tmp.y = j+1;
				q.push(tmp);
			}
		}
	}
	cout << q.size() << endl;
	while( !q.empty() )
	{
		Step tmp = q.front();
		q.pop();
		cout << tmp.x << " " << tmp.y << endl;
	}

	system("pause");

	return 0;
}