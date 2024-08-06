#pragma once

#include "exports.h"

#include "Matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

// int

EXPORTS_API Matrix<int>* new_matrix_int( int n, ... );
EXPORTS_API Matrix<int>* copy_matrix_int( const Matrix<int>* other );
EXPORTS_API void del_matrix_int( Matrix<int>* matrix );
EXPORTS_API int fill_matrix_int( Matrix<int>* matrix, int n, ... );
EXPORTS_API void print_matrix_int( Matrix<int>* matrix );

EXPORTS_API void sort_matrix_int( Matrix<int>* matrix );
EXPORTS_API int sum_matrices_int( Matrix<int>* variable, const Matrix<int>* fixed );
EXPORTS_API int sub_matrices_int( Matrix<int>* variable, const Matrix<int>* fixed );
EXPORTS_API int mul_matrices_int( Matrix<int>* variable, const Matrix<int>* fixed );

// double

EXPORTS_API Matrix<double>* new_matrix_double( int n, ... );
EXPORTS_API Matrix<double>* copy_matrix_double( const Matrix<double>* other );
EXPORTS_API void del_matrix_double( Matrix<double>* matrix );
EXPORTS_API int fill_matrix_double( Matrix<double>* matrix, int n, ... );
EXPORTS_API void print_matrix_double( Matrix<double>* matrix );

EXPORTS_API void sort_matrix_double( Matrix<double>* matrix );
EXPORTS_API int sum_matrices_double( Matrix<double>* variable, const Matrix<double>* fixed );
EXPORTS_API int sub_matrices_double( Matrix<double>* variable, const Matrix<double>* fixed );
EXPORTS_API int mul_matrices_double( Matrix<double>* variable, const Matrix<double>* fixed );


#ifdef __cplusplus
}
#endif


// --- definitions ---

namespace
{

template<class T>
Matrix<T>* new_matrix( int n, va_list* args )
{
    return new Matrix<T>( n, args );
}

template<class T>
Matrix<T>* copy_matrix( const Matrix<T>* other )
{
    return new Matrix<T>( *other );
}

template<class T>
void del_matrix( Matrix<T>* matrix )
{
    if ( !matrix )
    {
        return;
    }

    delete matrix;
}

template<class T>
int fill_matrix( Matrix<T>* matrix, int n, va_list* args )
{
    if ( !matrix )
    {
        return static_cast<int>( Error::InvalidArguments );
    }

    return matrix->fill( n, args );
}

template<class T>
void print_matrix( Matrix<T>* matrix )
{
    if ( !matrix )
    {
        return;
    }

    matrix->print();
}

template<class T>
void sort_matrix( Matrix<T>* matrix )
{
    matrix->sort();
}

template<class T>
int sum_matrices( Matrix<T>* variable, const Matrix<T>* fixed )
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

template<class T>
int sub_matrices( Matrix<T>* variable, const Matrix<T>* fixed )
{
    try
    {
        *variable -= *fixed;
    }
    catch ( int errorCode )
    {
        return errorCode;
    }

    return 0;
}

template<class T>
int mul_matrices( Matrix<T>* variable, const Matrix<T>* fixed )
{
    try
    {
        Matrix<T>* result = copy_matrix( variable );
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

}


Matrix<int>* new_matrix_int( int n, ... )
{
    va_list args;
    va_start( args, n );
    return new_matrix<int>( n, &args );
}

Matrix<int>* copy_matrix_int( const Matrix<int>* other )
{
    return copy_matrix<int>( other );
}

void del_matrix_int( Matrix<int>* matrix )
{
    del_matrix<int>( matrix );
}

int fill_matrix_int( Matrix<int>* matrix, int n, ... )
{
    va_list args;
    va_start( args, n );
    return fill_matrix<int>( matrix, n, &args );
}

void print_matrix_int( Matrix<int>* matrix )
{
    print_matrix<int>( matrix );
}

void sort_matrix_int( Matrix<int>* matrix )
{
    sort_matrix<int>( matrix );
}

int sum_matrices_int( Matrix<int>* variable, const Matrix<int>* fixed )
{
    return sum_matrices<int>( variable, fixed );
}

int sub_matrices_int( Matrix<int>* variable, const Matrix<int>* fixed )
{
    return sub_matrices<int>( variable, fixed );
}

int mul_matrices_int( Matrix<int>* variable, const Matrix<int>* fixed )
{
    return mul_matrices<int>( variable, fixed );
}