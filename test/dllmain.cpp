#include <Windows.h>
#include <string>
#include <imagehlp.h>


// For DLL mode
extern "C" __declspec(dllexport)
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		MessageBox(NULL, "Omg dll injected", "Injected!", MB_ICONEXCLAMATION | MB_OK);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

// Exporting function usable with SetWindowsHookEx
extern "C" __declspec(dllexport) int NextHook(int code, WPARAM wParam, LPARAM lParam) {
	return CallNextHookEx(NULL, code, wParam, lParam);
}