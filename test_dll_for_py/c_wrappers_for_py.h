#pragma once

#include "exports.h"

#include "Matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

EXPORTS_API Matrix* new_matrix( int n, ... );
EXPORTS_API void del_matrix( Matrix* Matrix );
EXPORTS_API int fill_matrix( Matrix* Matrix, int n, ... );
EXPORTS_API void call_matrix( Matrix* Matrix );

#ifdef __cplusplus
}
#endif