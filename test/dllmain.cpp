#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		//MessageBoxA(0, "DllMain", "DllMain", MB_OK);
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) LRESULT fnProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//MessageBoxA(0, "fnProc", "fnProc", MB_OK);
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}