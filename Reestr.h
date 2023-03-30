#ifndef REESTR_H
#define REESTR_H

#include "ReestrRecord.h"
#include <stdlib.h>
#include <stdio.h>

/**
* \struct Reestr
* \brief Структура для хранения массива структур ReestrRecord (массив записей файла Reestr.txt)
* \param reestr массив структур CatalogRecord
* \param length размер массива структур Catalog
*/

typedef struct Reestr
	{
	ReestrRecord** reestr;
	size_t length;
	} Reestr;

Reestr* create_Reestr();
void init_Reestr(FILE* file, Reestr* structure);
void add_ReestrRecord(Reestr* structure, ReestrRecord*);
void delete_Reestr(Reestr* structure);

#endif