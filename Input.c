#include "InputRecord.h"
#include "Functions.h"
#include "Input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* \brief ¬ыдел€ет пам€ть и создает массив структур InputRecord (массив записей файла inputTT.txt)
* \return выделение места под массив структур InputRecord
*/
Input* create_Input()
	{
	return (Input*)calloc(1, sizeof(Input));
	}

/**
* \brief ‘ункци€ "инициализирует" массив структур
* \param file входной файл, на основании которого считываютс€ данные
* \param structure структуры, пол€м которых будут присваиватьс€ значени€
* \return инициализированные структуры InputRecord
*/
void init_Input(FILE* file, Input* structure)
	{
	structure->length = 1;
	structure->input = (InputRecord**)calloc(structure->length, sizeof(InputRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		InputRecord* record = create_InputRecord();
		init_InputRecord(record, tmp);
		structure->input[i] = record;
		free(tmp);
		}
	}

/**
* \brief ‘ункци€ освобождает пам€ть Input
* \param structure структура, пам€ть которой будет освобождатьс€
* \return освобожденна€ пам€ть массива структур Input
*/
void delete_Input(Input* structure)
	{
	for (int i = 0; i < structure->length; i++)
		delete_InputRecord(structure->input[i]);
	free(structure->input);
	free(structure);
	}