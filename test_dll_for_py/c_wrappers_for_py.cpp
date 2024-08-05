#include "pch.h"

#include "c_wrappers_for_py.h"


Matrix* new_matrix( int n, ... )
{
    va_list args;
    va_start( args, n );
    return new Matrix( n, &args );
}

EXPORTS_API Matrix* copy_matrix( const Matrix* other )
{
    return new Matrix( *other );
}

void del_matrix( Matrix* matrix )
{
    if ( !matrix )
    {
        return;
    }

    delete matrix;
}

int fill_matrix( Matrix* matrix, int n, ... )
{
    if ( !matrix )
    {
        return static_cast<int>( Error::InvalidArguments );
    }

    va_list args;
    va_start( args, n );
    return matrix->fill( n, &args );
}

void call_matrix( Matrix* matrix )
{
    if ( !matrix )
    {
        return;
    }

    matrix->debugCall();
}

void sort_matrix( Matrix* matrix )
{
    matrix->sort();
}

int sum_matrix( Matrix* variable, const Matrix* fixed )
{
    *variable += *fixed;

    return 1;
}
