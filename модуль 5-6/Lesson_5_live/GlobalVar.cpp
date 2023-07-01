#include "GlobalVar.h"
#include <iostream>

int globalInt = 10;

void CheckGlobalVar()
{
	std::cout << __func__ << ": " << globalInt++ << std::endl;
}
