#include "pch.h"


bool DllMain( HMODULE hModule,
              DWORD  ul_reason_for_call,
              LPVOID lpReserved
)
{
    switch ( ul_reason_for_call )
    {
    case DLL_PROCESS_ATTACH:
        std::cout << "DllMain attach\n";
        break;
    case DLL_PROCESS_DETACH:
        std::cout << "DllMain detach\n";
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }

    return true;
}
