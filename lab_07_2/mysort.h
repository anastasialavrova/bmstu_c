#ifndef MYSORT_H
#define MYSORT_H

void copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst);
void mysort(void *pb, int n, size_t size, int(*compare)(const void*, const void*));
int compare_int(const void* f, const void* s);
//void swap(int *a, int *b);
void swap(void *p1, void *p2, size_t size);

#endif // MYSORT_H
