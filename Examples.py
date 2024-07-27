from ctypes import cdll


libname = 'x64/Release/test_dll_for_py.dll' 
lib = cdll.LoadLibrary(libname)

lib.testFunc()
# matrix = lib.createMatrix()
