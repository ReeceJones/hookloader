#include <iostream>
#include <Windows.h>

int main()
{
	//load our library into memory using loadlibrary (if you can use another method if you feel like it)
	LPSTR buf = (LPSTR)malloc(MAX_PATH);
	GetFullPathNameA("test.dll", MAX_PATH, buf, NULL);
	auto mod = LoadLibraryA(buf);
	//find the address of the proxy function in our dll
	auto fn = (HOOKPROC)GetProcAddress(mod, "fnProc");
	//set the hook using our dll and our proxy method
	auto hook = SetWindowsHookEx(/*WH_KEYBOARD_LL*/WH_CALLWNDPROC, fn, mod, NULL);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//remove our hook to be safe
	UnhookWindowsHookEx(hook);
	return 0;
}