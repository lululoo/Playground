#pragma once

#ifdef DLLPROJECT
	#define DLLAPI __declspec( dllexport)
#else
	#define DLLAPI __declspec( dllimport )
#endif