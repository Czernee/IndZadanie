#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

/**
* \brief Заголовочный файл с некоторыми функциями
*/

char* fread_string(FILE* file);
int check_file(FILE* file);
char* get_month(char* date);
char* get_year(char* date);
char** separate_date(char* date);


#endif