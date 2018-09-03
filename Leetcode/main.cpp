#include <iostream>
#include <Windows.h>

#include "Base.hpp"
using namespace std;

#include "Problem\447.hpp"

extern CSolutionBase* gpBase;

int main(int argc, char** argv)
{
	
	if(gpBase )
	{
		gpBase->run();
	}

	system("pause");
	return 0;
}