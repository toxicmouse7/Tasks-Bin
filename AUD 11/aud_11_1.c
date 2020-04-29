#include <stdio.h>
#include <windows.h>
#include <conio.h>

long filesize(FILE* file)
{
	long cur, end;
	cur = ftell(file);
	fseek(file, 0, SEEK_END);
	end = ftell(file);

	return end - cur;
}

//void wchar_to_char(wchar_t* filename, )
//{
//	char char_filename[260];
//	int i = 0;
//	do
//	{
//		char_filename[i] = filename[i];
//	} while (filename[i] != '\0');
//
//	return char_filename;
//}

int main()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;

	hf = FindFirstFile(L"*.txt", &FindFileData);

	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (FindFileData.nFileSizeLow > 20)
				wprintf(L"%s\n", FindFileData.cFileName);

		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}
	else printf("An error has occurred (%d)\n", GetLastError());

	_getch();
	return 0;
}