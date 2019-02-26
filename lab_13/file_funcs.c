#include "list.h"

/**
 Подсчитывание кол-ва строк в файле

 @param file - указатель на файл
 @return кол-во считанных строк
 */
int num_of_strings(FILE *file)
{
    int num = 0;
    char c;
    while(fscanf(file,"%c",&c) == 1)
        if (c == '\n')
        {
            num++;
        }
    rewind(file);

    return num;
}

/*
 Считывание числа из файла

 @param file [in]
 @param num [in]
 */
void read_num_from_file(FILE *file, int *num)
{
    char c;
    fscanf(file, "%d", num);
    do
    {
        fscanf(file, "%c", &c);
    } while (c != '\n');

}

/*
 Проверка файла на успешное открытие и на пустоту

 @param file [in]
 @return Возвращает OK, если ошибок не было, либо ERR_PARAM, если произошла ошибка открытия файла
 */
int check_file(FILE *file)
{
    int err = 0;
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        long pos = ftell(file);
        if (!(pos > 1))
        {
            puts("File is empty");
            err = -1;
            fclose(file);
        }
        else
            rewind(file);
    }
    else
    {
        puts("File doesn't exist");
        err = -2;
    }
    return err;
}

/*
 Считывание строки из файла

 @param file [in]
 @param string [in]
 */
void read_string(FILE *file, char *string)
{
    int k = 0, index_space = 0;
    char c;
    fscanf(file, "%c", &c);

    while (c == ' ')
        fscanf(file, "%c", &c);
    while(c != ';' && c != '\n')
    {
        if (c == ' ' && string[k-1] != ' ')
            index_space = k-1;
        string[k++] = c;
        fscanf(file, "%c", &c);
    }
    if (string[k-1] == ' ')
        string[index_space+1] = '\0';
    else
        string[k] = '\0';
}

/**
 Считывание целого числа, введенное пользователем

 @param num [in]
 @param message [in]
 */
void read_num(int *num, char message[])
{
    int rc;
    char tmp;
    printf("%s", message);
    while(((rc = scanf("%d%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("Input error.  %s", message);
        do
            rc = scanf("%c", &tmp);
        while(rc != EOF && tmp != '\n');
    }
}
