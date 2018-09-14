#include <iostream>
#include <Windows.h>

#include "Base.hpp"
using namespace std;

#include "Problem\137.hpp"

extern CSolutionBase* gpBase;

int main(int argc, char** argv)
{
	
	int i = 0;

	if(gpBase )
	{
		gpBase->run();
	}

	system("pause");
	return 0;
}