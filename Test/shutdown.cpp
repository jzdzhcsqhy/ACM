#include <iostream>
#include <windows.h>
using namespace std;

int main( int argc, char** argv )
{

	while( true )
	{
		cout<< "����������Ҫ����Ժ�ػ�����λ�����ӣ���" ;
		int iTime;
		cin>> iTime;

		iTime = iTime*60;
		if( 0 > iTime )
		{
			cout << "����������������������!" << endl;
		}
		else
		{
			char sCmd[100];
			sprintf(sCmd, "shutdown -s -t %d", iTime);
			int iRs = system(sCmd);
			if( 0 == iRs )
			{
				cout << "�ɹ���ϵͳ����" << iTime/60 <<"���Ӻ�ػ���" << endl;
				system("sleep 10");
				return ;
			}
		}
	}
}