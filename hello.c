#include <windows.h>

void hello()
{
    MessageBox(NULL, "Hello World", "Payload", MB_OK);
}

BOOL WINAPI DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        hello();
    }
    return TRUE;
}