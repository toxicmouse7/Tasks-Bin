#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <locale.h>

int main()
{
    HANDLE hProcessSnap;
    HANDLE hProcess;
    DWORD perem;
    PROCESSENTRY32 pe32;
    int flag;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    pe32.dwSize = sizeof(PROCESSENTRY32);
    //perem = pe32.th32ParentProcessID;
    Process32First(hProcessSnap, &pe32);

    do
    {
        

    } while (Process32Next(hProcessSnap, &pe32));
}