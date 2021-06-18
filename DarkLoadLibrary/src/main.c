#include <stdio.h>
#include <windows.h>

#include "darkloadlibrary.h"

typedef DWORD (WINAPI * _ThisIsAFunction) (LPCWSTR);

int main()
{
	DARKMODULE DarkModule = DarkLoadLibrary(
		LOAD_LOCAL_FILE,
		L"TestDLL.dll",
		NULL,
		0,
		NULL
	);

	if (!DarkModule.bSuccess)
	{
		printf("load failed: %S\n", DarkModule.ErrorMsg);
		return 1;
	}

	_ThisIsAFunction ThisIsAFunction = GetProcAddress(
		DarkModule.ModuleBase,
		"CallThisFunction"
	);

	if (!ThisIsAFunction)
	{
		printf("failed to find it\n");
		return 1;
	}

    ThisIsAFunction(L"this is working!!!");

	return 0;
}