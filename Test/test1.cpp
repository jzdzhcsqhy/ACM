#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x = 5;
	printf("%d and ", sizeof(x++)); // note 1
	printf("%d\n", x); // note 2
	x++;
	int a = sizeof(x++);
	system("pause");
	return 0;
}