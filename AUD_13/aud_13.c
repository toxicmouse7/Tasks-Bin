#define INITGUID
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <VersionHelpers.h>
#include <SetupAPI.h>


int main()
{
	HANDLE Handle;
	SP_DEVINFO_DATA DeviceInfoData;
	ZeroMemory(&DeviceInfoData, sizeof(SP_DEVINFO_DATA));
	DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	DWORD DeviceIndex = 0;
	BYTE PropertyBuffer[1024] = { 0 };

	Handle = SetupDiGetClassDevsW(NULL, NULL, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
	
	while (SetupDiEnumDeviceInfo(Handle, DeviceIndex, &DeviceInfoData))
	{

		SetupDiGetDeviceRegistryPropertyW(Handle, &DeviceInfoData, SPDRP_MFG, NULL, PropertyBuffer, 1024, NULL);

		printf("%s\n", (char*)&PropertyBuffer);

		DeviceIndex++;
	}

	if (!IsWindows7OrGreater())
	{
		printf("Come on. It is 2020, but you still using XP? Dude...");
		exit(1);
	}

	if (IsWindows10OrGreater())
		printf("Operating System: Windows 10");
	else if (IsWindows8Point1OrGreater())
		printf("Operating System: Windows 8.1");
	else if (IsWindows8OrGreater())
		printf("Operating System: Windows 8");
	else if (IsWindows7OrGreater())
		printf("Operating System: Windows 7");

	return NULL;
}