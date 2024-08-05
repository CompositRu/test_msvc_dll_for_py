#include "pch.h"

#include "c_wrappers_for_py.h"


Matrix* new_matrix( int n, ... )
{
    va_list args;
    va_start( args, n );
    return new Matrix( n, &args );
}

void del_matrix( Matrix* Matrix )
{
    delete Matrix;
}

int fill_matrix( Matrix* Matrix, int n, ... )
{
    va_list args;
    va_start( args, n );
    return Matrix->fill( n, &args );
}

void call_matrix( Matrix* Matrix )
{
    if ( !Matrix )
    {
        return;
    }

    Matrix->debugCall();
}