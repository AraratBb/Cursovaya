// dllmain.cpp : Defines the entry point for the DLL application.
#include "framework.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks _l_;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    srand(time(NULL));
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}