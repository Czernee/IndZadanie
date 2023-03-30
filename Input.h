#ifndef INPUT_H
#define INPUT_H

#include "InputRecord.h"
#include <stdlib.h>
#include <stdio.h>

/**
* \struct Input
* \brief Структура для хранения массива структур InputRecord (массив записей файла inputTT.txt)
* \param input запись файла inputTT.txt
* \param lenght размер структуры
*/

typedef struct Input
	{
	InputRecord** input;
	size_t length;
	} Input;

Input* create_Input();
void init_Input(FILE* file, Input* structure);
void delete_Input(Input* structure);

#endif
