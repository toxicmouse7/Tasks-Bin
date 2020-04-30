#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main()
{
	WIN32_FIND_DATA FindFileData;
	STARTUPINFO info;
	PROCESS_INFORMATION procinfo;
	HANDLE hf;

	ZeroMemory(&info, sizeof(info));
	info.cb = sizeof(info);
	ZeroMemory(&procinfo, sizeof(procinfo));

	hf = FindFirstFile(L"*.*", &FindFileData);

	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (CreateProcess(FindFileData.cFileName, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &info, &procinfo) != 0)
			{
				wprintf(L"%s\n", FindFileData.cFileName);
				TerminateProcess(procinfo.hProcess, 259);
				CloseHandle(procinfo.hProcess);
			}

		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}

	_getch();
	return 0;
}