#include "iostream"
#include <queue>
#include <map>
using namespace std;

typedef struct 
{	
	unsigned int input;
	int step;
}Step;
bool flag[65540];
unsigned int change( unsigned int input, int pos )
{
	unsigned int t = 0x00000000;
	unsigned one = 0x00000001;

	unsigned int dp[16]={19,39,78,140,305,626,1252,2248,4880,
		10016,20032,35968,12544,29184,58368,51200};

	if( pos <0 || pos >=16 )
	{
		return input;
	}
	else
	{
		return input ^ dp[pos];
	}

	
}

void check( unsigned int input )
{
	memset(flag, 0, sizeof(flag));
	queue<Step > q;
	Step st;
	st.input = input;
	st.step = 0;
	flag[input] = true;
	q.push(st);
	while( !q.empty() )
	{
		st = q.front();
		q.pop();
		if( st.input == 0x00000000 || st.input== 0x0000ffff )
		{
			cout << st.step << endl;
			return ;
		}

		for( int i=0; i<16; i++ )
		{
			unsigned tt = change(st.input, i);
			if(flag[tt] == false && tt != input )
			{
				flag[tt] = true;
				Step tmpst;
				tmpst.step = st.step +1;
				tmpst.input = tt;
				q.push(tmpst);
			}
		}
		
	}
	cout <<"Impossible" << endl;
}

int main( int argc, char** argv )
{
	char ch;
	int cnt = 15;
	unsigned int input = 0;
	unsigned int one = 1;

	while( ch = getchar() )
	{
		if( ch !='b' && ch != 'w')
		{
			continue;
		}
		else
		{
			if('b' == ch )
			{
				input += one << cnt; 
			}
			cnt --;
			if( cnt <0 )
			{
				check(input);
				break;
			}
			
		}
	}
	return 0;
}