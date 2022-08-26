#pragma once
#ifdef MYKLIBL_EXPORTS
#   ifdef _WINDLL
#       define MYKLIB_API __declspec(dllexport)
#   elif __linux__
#       define MYKLIB_API 
#   endif
#else
#   ifdef _WINDLL
#       define MYKLIB_API __declspec(dllimport)
#   elif __linux__
#       define MYKLIB_API
#   else //何も指定しない
#       define MYKLIB_API 
#       define MYKLIB_API 
#   endif
#endif
