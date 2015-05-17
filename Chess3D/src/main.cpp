#include <iostream>
#include <Windows.h>
#include "application.h"

using namespace std;

int main(void)
{
	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);
	std::cout << NPath << std::endl;
    Application::start();
}
