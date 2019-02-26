
#ifndef LAB_11_FUNC_H
#define LAB_11_FUNC_H

void move_ptr(char **ptr, int *ptr_len, int step);
int numbers(const char **format, char **s, int *s_len, int num);
void negative(char **s, int *s_len, int *num);
int count_len(int num, int base);
void add_num(char **s, int *s_len, int num, int base);

#endif //LAB_11_FUNC_H
