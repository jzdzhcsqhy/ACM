#include <iostream>
#include <windows.h>
using namespace std;

int main( int argc, char** argv )
{

	while( true )
	{
		cout<< "请问您想想要多久以后关机（单位：分钟）：" ;
		int iTime;
		cin>> iTime;

		iTime = iTime*60;
		if( 0 > iTime )
		{
			cout << "输入数据有误，请重新输入!" << endl;
		}
		else
		{
			char sCmd[100];
			sprintf(sCmd, "shutdown -s -t %d", iTime);
			int iRs = system(sCmd);
			if( 0 == iRs )
			{
				cout << "成功！系统将在" << iTime/60 <<"分钟后关机！" << endl;
				system("sleep 10");
				return ;
			}
		}
	}
}