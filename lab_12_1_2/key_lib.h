#ifndef __KEY__H__
#define __KEY__H__

#ifdef EXPORTS
#define KEY_DLL __declspec(dllexport)
#else
#define KEY_DLL __declspec(dllimport)
#endif

#define KEY_DECL __cdecl

KEY_DLL int KEY_DECL key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst);

#endif
