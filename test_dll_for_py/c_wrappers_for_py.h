#pragma once

#include "exports.h"

#include "Matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

EXPORTS_API Matrix* new_matrix( int n, ... );
EXPORTS_API Matrix* copy_matrix( const Matrix* other );
EXPORTS_API void del_matrix( Matrix* matrix );
EXPORTS_API int fill_matrix( Matrix* matrix, int n, ... );
EXPORTS_API void call_matrix( Matrix* matrix );

EXPORTS_API void sort_matrix( Matrix* matrix );
EXPORTS_API int sum_matrix( Matrix* variable, const Matrix* fixed );

#ifdef __cplusplus
}
#endif