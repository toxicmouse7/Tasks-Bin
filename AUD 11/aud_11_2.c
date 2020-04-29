#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define executables 4

int main()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	int i = 0;
	wchar_t file_type[executables][6];
	wcscpy_s(file_type[0], 6, L"*.txt");
	wcscpy_s(file_type[1], 6, L"*.bin");
	wcscpy_s(file_type[2], 6, L"*.jar");
	wcscpy_s(file_type[3], 6, L"*.pyc");

	start:

	hf = FindFirstFile(file_type[i], &FindFileData);

	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (FindFileData.nFileSizeLow > 20)
				wprintf(L"%s\n", FindFileData.cFileName);

		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
		i++;
		if (i < executables)
			goto start;
	}
	else
	{
		if (i < executables)
		{
			i++;
			goto start;
		}
		else printf("Nothing else was finded, sorry :C\n");
	}

	_getch();
	return 0;
}