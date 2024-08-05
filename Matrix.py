from ctypes import cdll
import ctypes as ct
from enum import Enum


def call_func( func, arg_list, return_type = None ):
    size = len( arg_list )
    func.argtypes = [ct.c_int, *( size * [ct.c_int] )]
    if return_type:
        func.restype = return_type
    return func( size, *arg_list )


def call_node_func( node, func, arg_list = [] ):
    size = len( arg_list )
    func.restype = ct.c_int
    if len(arg_list) > 0:
        func.argtypes = [ct.c_void_p, ct.c_int, *( size * [ct.c_int] )]
        return func( node, size, *arg_list )
    else:
        func.argtypes = [ct.c_void_p]
        return func( node )


libname = 'x64/Release/test_dll_for_py.dll' 
lib = cdll.LoadLibrary(libname)


class Error(Enum):
    success = 0
    invalid_arguments = 1


error_description = {
    Error.success : "success",
    Error.invalid_arguments : "invalid arguments"
}


class Matrix: 
    def __init__(self, dimensions = []):
        self.matrix_obj = call_func( lib.new_matrix, dimensions, ct.c_void_p )

    def __del__(self):
        call_node_func( self.matrix_obj, lib.del_matrix )

    def fill(self, values = []):
        error = call_node_func( self.matrix_obj, lib.fill_matrix, values )
        if error != Error.success.value:
            raise Exception( error_description[Error(error)])

    def print(self):
        call_node_func( self.matrix_obj, lib.call_matrix )