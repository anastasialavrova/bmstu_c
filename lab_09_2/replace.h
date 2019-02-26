
#ifndef LAB_9_2_REPLACE_H
#define LAB_9_2_REPLACE_H

#define BUF_SIZE 10
#define SIZE 10

char *str_replace(const char *str, const char *search, const char *replace);
void add_symbol(char *str, char *search, char *replace, char **my_str, int *max_size, int *curr_size, int *i);

#endif //LAB_9_2_REPLACE_H
