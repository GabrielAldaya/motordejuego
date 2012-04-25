#ifndef DEFINES_H
#define DEFINE_H
//------------------------------------------------------------------------
#include <windows.h>
//------------------------------------------------------------------------
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif // engine_exports
//------------------------------------------------------------------------
#endif // defines_h