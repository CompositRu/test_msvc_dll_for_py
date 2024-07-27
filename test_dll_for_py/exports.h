#pragma once

#ifdef WIN32
#   ifdef TESTDLLFORPY_EXPORTS
#       define EXPORTS_API __declspec(dllexport)
#   else
#       define EXPORTS_API __declspec(dllimport)
#   endif
#else
#       define EXPORTS_API
#endif
