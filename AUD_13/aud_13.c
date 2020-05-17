#define INITGUID
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <SetupAPI.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	HANDLE Handle;
	SP_DEVINFO_DATA DeviceInfoData;
	ZeroMemory(&DeviceInfoData, sizeof(SP_DEVINFO_DATA));
	DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	DWORD DeviceIndex = 0;
	BYTE PropertyBuffer[1024] = { 0 };
	BYTE PropertyBuffer_HWID[1024] = { 0 };
	BYTE PropertyBuffer_cmp[1024] = { 0 };
	LPSTR name[30];
	DWORD pcbBuffer = 30;
	RTL_OSVERSIONINFOW sys_info;

	GetUserNameA(name, &pcbBuffer);
	printf("User Name: %s\n", name);
	pcbBuffer = 30;
	GetComputerNameA(name, &pcbBuffer);
	printf("Computer Name: %s\n", name);

	printf("Connected devices:\n");

	Handle = SetupDiGetClassDevsA(NULL, NULL, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
	
	while (SetupDiEnumDeviceInfo(Handle, DeviceIndex, &DeviceInfoData))
	{
		strcpy_s(PropertyBuffer_cmp, 1024, PropertyBuffer);
		SetupDiGetDeviceRegistryPropertyA(Handle, &DeviceInfoData, SPDRP_FRIENDLYNAME, NULL, PropertyBuffer, 1024, NULL);

		if (strcmp(PropertyBuffer, PropertyBuffer_cmp))
		{
			SetupDiGetDeviceRegistryPropertyA(Handle, &DeviceInfoData, SPDRP_HARDWAREID, NULL, PropertyBuffer_HWID, 1024, NULL);
			printf("	- %s HWID: %s\n", PropertyBuffer, PropertyBuffer_HWID);
		}
		else 
		{ 
			DeviceIndex++;
			continue;
		}
	}

	printf("\n");

	

	return NULL;
}