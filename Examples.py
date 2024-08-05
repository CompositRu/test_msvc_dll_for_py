from ctypes import cdll
import ctypes as ct


def call_func( func, arg_list, return_type = None ):
    size = len( arg_list )
    func.argtypes = [ct.c_int, *( size * [ct.c_int] )]
    if return_type:
        func.restype = return_type
    return func( size, *arg_list )


def call_node_func( node, func, arg_list = [] ):
    size = len( arg_list )
    if len(arg_list) > 0:
        func.argtypes = [ct.c_void_p, ct.c_int, *( size * [ct.c_int] )]
        func( node, size, *arg_list )
    else:
        func.argtypes = [ct.c_void_p]
        func( node )


libname = 'x64/Release/test_dll_for_py.dll' 
lib = cdll.LoadLibrary(libname)


node = call_func( lib.new_matrix, [2, 2, 2], ct.c_void_p )
call_node_func( node, lib.fill_matrix, [5, 6, 7, 8, 1, 2, 3, 4] )
call_node_func( node, lib.call_matrix )