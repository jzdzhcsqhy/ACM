#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string>

using namespace std;

int main(void)
{
	char str[122];
	memset(str,'0',sizeof(str));
	sprintf(str,"%016s","1234");
	printf("%s\n",str);
	system("pause");
}