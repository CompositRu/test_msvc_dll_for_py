#include "pch.h"

#include "Matrix.h"


void CheckMatrix()
{
    //auto node = Node( 2, 3, 4 );
    //node.setValue( 1, 1, 1, 7. );
    //node.setValue( 1, 5. );

    auto node = Node( 2, 2, 2 );
    node.fill( 1, 2, 3, 4, 5, 6, 7, 8 );
    node.call();
}

bool DllMain( HMODULE hModule,
              DWORD  ul_reason_for_call,
              LPVOID lpReserved
)
{
    switch ( ul_reason_for_call )
    {
    case DLL_PROCESS_ATTACH:
        //std::cout << "DllMain attach\n";
        CheckMatrix();
        break;
    case DLL_PROCESS_DETACH:
        //std::cout << "DllMain detach\n";
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }

    return true;
}
