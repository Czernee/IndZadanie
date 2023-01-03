#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>

char* fread_string(FILE* file) 
    {

    char* string = (char*)calloc(1, sizeof(char));
    size_t length = 1;
    string[0] = '\0';
    while (1)
        {
        char symbol = fgetc(file);
        if (symbol == '\n')
            {
            break;
            }
        length++;
        string = (char*)realloc(string, length * sizeof(char));
        string[length - 1] = '\0';
        string[length - 2] = symbol;
        }
    return string;
    }

void check_file(FILE* file)
    {
    if (file == NULL)
        {
        printf("This file doesn't exist\n");
        exit(1);
        }
    }