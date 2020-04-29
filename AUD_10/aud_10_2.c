#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <locale.h>

DWORD MyPPID(wchar_t* exename)
{
    DWORD PPID;
    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    pe32.dwSize = sizeof(PROCESSENTRY32);
    Process32First(hProcessSnap, &pe32);

    do
    {
        hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);

        if (wcscmp(pe32.szExeFile, exename) == 0)
        {
            PPID = pe32.th32ParentProcessID;
        }

    } while (Process32Next(hProcessSnap, &pe32));

    return PPID;
}

void FindCurrentProcessName(wchar_t* exename, char* exestring)
{
    int size, i = 0;
    size = strlen(exestring);
    while (exestring[size] != '\\')
        size--;
    size++;
    while (exestring[size] != '\0')
    {
        exename[i] = exestring[size];
        i++;
        size++;
    }
    exename[i] = '\0';
}

int main(int argc, char* argv[])
{
    HANDLE Mutex;
    Mutex = CreateMutex(NULL, TRUE, "MutexOfTheMyApplication");
    DWORD result;
    result = WaitForSingleObject(Mutex, NULL);

    if (result != WAIT_OBJECT_0)
    {
        printf("The program is already running!\n");
        system("pause");
        return 0;
    }
    else printf("The program is running\n");

    //setlocale(LC_ALL, "Russian");
    //HANDLE hProcessSnap;
    //HANDLE hProcess;
    //DWORD PPID;
    //char exestring[260];
    //wchar_t exename[260];
    //strcpy_s(exestring, 260, argv[0]);
    //PROCESSENTRY32 pe32;
    //int flag = 0;
    //

    //FindCurrentProcessName(exename, exestring);
    //PPID = MyPPID(exename);
    //system("pause");

    //hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    //pe32.dwSize = sizeof(PROCESSENTRY32);
    //Process32First(hProcessSnap, &pe32);

    //do
    //{
    //    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);

    //    if (PPID == pe32.th32ParentProcessID)
    //    {
    //        printf("%lli\n", pe32.th32ProcessID);
    //        flag++;
    //        wprintf(L"%s\n", pe32.szExeFile);
    //        system("pause");
    //    }

    //    /*if (flag > 2)
    //    {
    //        printf("suka\n");
    //        exit(2);
    //    }*/

    //} while (Process32Next(hProcessSnap, &pe32));
    

    _getche();
}