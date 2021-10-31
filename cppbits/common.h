#pragma once

#ifdef CPPBITS_EXPORTS
#define CPPBITS_API __declspec(dllexport)
#else
#define CPPBITS_API __declspec(dllimport)
#endif
