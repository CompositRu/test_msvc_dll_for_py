from ctypes import cdll
import ctypes as ct
from enum import Enum


def call_variadic_func( func, arg_list, return_type = None ):
    size = len( arg_list )
    func.argtypes = [ct.c_int, *( size * [ct.c_int] )]
    if return_type:
        func.restype = return_type
    return func( size, *arg_list )


def call_node_variadic_func( node, func, arg_list = [] ):
    size = len( arg_list )
    func.restype = ct.c_int
    if len(arg_list) > 0:
        func.argtypes = [ct.c_void_p, ct.c_int, *( size * [ct.c_int] )]
        return func( node, size, *arg_list )
    else:
        func.argtypes = [ct.c_void_p]
        return func( node )


def call_two_nodes_func( func, node1, node2 ):
    func.restype = ct.c_int
    func.argtypes = [ct.c_void_p, ct.c_void_p] # variable matrix, fixed matrix
    return func( node1, node2 )       


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
    def __init__(self, dimensionsOrOtherObj):
        if isinstance(dimensionsOrOtherObj, list):
            dimensions = dimensionsOrOtherObj
            self.matrix_obj = call_variadic_func( lib.new_matrix, dimensions, ct.c_void_p )
        else:
            matrix_obj = dimensionsOrOtherObj
            self.matrix_obj = matrix_obj

    # def __init__(self, matrix_obj):
    #     self.matrix_obj = matrix_obj
    #     print( "self.matrix_obj 2", self.matrix_obj )

    def __del__(self):
        call_node_variadic_func( self.matrix_obj, lib.del_matrix )

    def fill(self, values = []):
        error = call_node_variadic_func( self.matrix_obj, lib.fill_matrix, values )
        if error != Error.success.value:
            raise Exception( error_description[Error(error)])

    def print(self):
        call_node_variadic_func( self.matrix_obj, lib.call_matrix )

    def __add__(self, other):
        lib.copy_matrix.restype = ct.c_void_p
        lib.copy_matrix.argtypes = [ct.c_void_p]
        result_obj = lib.copy_matrix( self.matrix_obj )
        error = call_two_nodes_func( lib.sum_matrices, result_obj, other.matrix_obj )
        if error != Error.success.value:
            raise Exception( error_description[Error(error)])
        return Matrix( result_obj )

    def __mul__(self, other):
        lib.copy_matrix.restype = ct.c_void_p
        lib.copy_matrix.argtypes = [ct.c_void_p]
        result_obj = lib.copy_matrix( self.matrix_obj )
        error = call_two_nodes_func( lib.mul_matrices, result_obj, other.matrix_obj )
        if error != Error.success.value:
            raise Exception( error_description[Error(error)])
        return Matrix( result_obj )