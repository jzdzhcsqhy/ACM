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
		cout << "师父大人有何吩咐: 1 -- 设置关机 2 -- 取消关机 3 -- 退出" << endl;
		int iOperate;
		cin >> iOperate;

		if( 1 == iOperate )
		{
			cout<< "师父大人想要多久以后关机?输入一个数字！输入0马上就关机！（单位：分钟）：" ;
			int iTime;
			cin>> iTime;
				
			if( cin.fail() )
			{
				cout << "不能乱输入啊，说好的输入数字" << endl;
				system("pause");
				continue;
			}

			iTime = iTime*60;
			if( 0 > iTime )
			{
				cout << "输入数据有误，请重新输入!" << endl;
			}
			else
			{
				if( 0 == iTime )
				{
					cout << "注意，你输入的是0！！！！！！！！！！！" << endl;
					cout << "当你按任意键之后，电脑将马上关闭！！！" << endl;
					cout << "请确保你要的东西都保存之后，回到这里按任意键关机！" << endl;
					system("pause");
				}
				char sCmd[100];
				sprintf(sCmd, "shutdown -s -t %d", iTime);
				int iRs = system(sCmd);
				if( 0 == iRs )
				{
					cout << "设置成功！电脑将在" << iTime/60 <<"分钟后关机！" << endl << endl << endl;
					cout << "师父大人晚安！   ^_^" << endl << endl << endl;
					system("pause");
					return 0;
				}
				else
				{
					cout << endl << "出了个错误 @_@"<< endl;
					cout << "如果你看到了 “已经计划系统关机（1190）”，说明你已经设置了自动关机，那就没关系了。"<< endl;
					cout << "否则，请联系你无敌的徒弟" << endl;
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
				cout << "已成功取消自动关机！" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "如果上面一行字说你没有任何关机进程，那没事，否则，请联系你无敌的徒弟" << endl;
				system("pause");
				continue;
			}
		}
		else if( 3 == iOperate )
		{
			cout << "师父再见!" << endl;
			system("pause");
			return 0;
		}
		else
		{
			cout << "输入的不对，徒弟做不到啊!" << endl;
			system("pause");
			continue;
		}
		
	}
}
