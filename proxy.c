#include <windows.h>

void Payload()
{
    MessageBox(NULL, "Hello from proxy dll", "Payload", MB_OK);
}

BOOL WINAPI DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			/* create a thread here... if a start function blocks--it could hold up other
			   DLLs loading and then nothing will appear to work */
            Payload();
    		break;

		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			break;
    }

    return TRUE;
}
