#include <iostream>
#include <windows.h>
using namespace std;

int main( int argc, char** argv )
{

	while( true )
	{
		system("cls");
		cin.clear();
		fflush(stdin);
		cout << "ʦ�������кηԸ�: 1 -- ���ùػ� 2 -- ȡ���ػ� 3 -- �˳�" << endl;
		int iOperate;
		cin >> iOperate;

		if( 1 == iOperate )
		{
			cout<< "ʦ��������Ҫ����Ժ�ػ�?����һ�����֣�����0���Ͼ͹ػ�������λ�����ӣ���" ;
			int iTime;
			cin>> iTime;
				
			if( cin.fail() )
			{
				cout << "���������밡��˵�õ���������" << endl;
				system("pause");
				continue;
			}

			iTime = iTime*60;
			if( 0 > iTime )
			{
				cout << "����������������������!" << endl;
			}
			else
			{
				if( 0 == iTime )
				{
					cout << "ע�⣬���������0����������������������" << endl;
					cout << "���㰴�����֮�󣬵��Խ����Ϲرգ�����" << endl;
					cout << "��ȷ����Ҫ�Ķ���������֮�󣬻ص����ﰴ������ػ���" << endl;
					system("pause");
				}
				char sCmd[100];
				sprintf(sCmd, "shutdown -s -t %d", iTime);
				int iRs = system(sCmd);
				if( 0 == iRs )
				{
					cout << "���óɹ������Խ���" << iTime/60 <<"���Ӻ�ػ���" << endl << endl << endl;
					cout << "ʦ����������   ^_^" << endl << endl << endl;
					system("pause");
					return 0;
				}
				else
				{
					cout << endl << "���˸����� @_@"<< endl;
					cout << "����㿴���� ���Ѿ��ƻ�ϵͳ�ػ���1190������˵�����Ѿ��������Զ��ػ����Ǿ�û��ϵ�ˡ�"<< endl;
					cout << "��������ϵ���޵е�ͽ��" << endl;
					system("pause");
					continue;
				}
			}
		}
		else if ( 2 == iOperate ) 
		{
			char sCmd[100];
			sprintf(sCmd, "shutdown -a");
			int iRs = system(sCmd);
			if( 0 == iRs )
			{
				cout << "�ѳɹ�ȡ���Զ��ػ���" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "�������һ����˵��û���κιػ����̣���û�£���������ϵ���޵е�ͽ��" << endl;
				system("pause");
				continue;
			}
		}
		else if( 3 == iOperate )
		{
			cout << "ʦ���ټ�!" << endl;
			system("pause");
			return 0;
		}
		else
		{
			cout << "����Ĳ��ԣ�ͽ����������!" << endl;
			system("pause");
			continue;
		}
		
	}
}
