#include <iostream>

using namespace std;

int main( int argc, char** argv )
{
	int a = 112233;
	char str[100];
	memset(str, 0 ,sizeof(str) );

	itoa(a, str, 3 );
	cout << str <<endl;

	str[strlen(str)-1] = '\0';

	cout << strtol(str, NULL, 3) << endl;


	system("pause");
	return 0;
}