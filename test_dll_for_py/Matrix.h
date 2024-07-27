#pragma once

#ifdef WIN32
#   ifdef TESTDLLFORPY_EXPORTS
#       define TESTDLLFORPY_EXPORTS_API __declspec(dllexport)
#   else
#       define TESTDLLFORPY_EXPORTS_API __declspec(dllimport)
#   endif
#else
#       define TESTDLLFORPY_EXPORTS_API
#endif

extern "C" void TESTDLLFORPY_EXPORTS_API testFunc();