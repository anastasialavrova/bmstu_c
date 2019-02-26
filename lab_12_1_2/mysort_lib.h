#ifndef __MYSORT__H__
#define __MYSORT__H__

#ifdef EXPORTS
#define MYSORT_DLL __declspec(dllexport)
#else
#define MYSORT_DLL __declspec(dllimport)
#endif

#define MYSORT_DECL __cdecl

MYSORT_DLL void MYSORT_DECL copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst);
MYSORT_DLL void MYSORT_DECL mysort(void *pb, int n, size_t size, int(*compare)(const void*, const void*));
MYSORT_DLL int MYSORT_DECL compare_int(const void* f, const void* s);
MYSORT_DLL void MYSORT_DECL swap(void *p1, void *p2, size_t size);

#endif
