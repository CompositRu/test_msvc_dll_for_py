#include "pch.h"

#include "c_wrappers_for_py.h"


Matrix* new_matrix( int n, ... )
{
    va_list args;
    va_start( args, n );
    return new Matrix( n, &args );
}

Matrix* copy_matrix( const Matrix* other )
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

    matrix->print();
}

void sort_matrix( Matrix* matrix )
{
    matrix->sort();
}

int sum_matrices( Matrix* variable, const Matrix* fixed )
{
    try
    {
        *variable += *fixed;
    }
    catch ( int errorCode )
    {
        return errorCode;
    }

    return 0;
}

int mul_matrices( Matrix* variable, const Matrix* fixed )
{   
    try
    {
        Matrix* result = copy_matrix( variable );
        *result *= *fixed;
        variable->swap( std::move( *result ) );
        del_matrix( result );
    }
    catch ( int errorCode )
    {
        return errorCode;
    }

    return 0;
}
