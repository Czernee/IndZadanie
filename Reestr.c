#include "ReestrRecord.h"
#include "Functions.h"
#include "Reestr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* \brief ¬ыдел€ет пам€ть и создает массив структур ReestrRecord (массив записей файла Catalog.txt)
* \return выделение места под массив структур CatalogRecord
*/
Reestr* create_Reestr()
	{
	return (Reestr*)calloc(1, sizeof(Reestr));
	}

/**
* \brief ‘ункци€ "инициализирует" массив структур
* \param file входной файл, на основании которого считываютс€ данные
* \param structure структуры, пол€м которых будут присваиватьс€ значени€
* \return инициализированные структуры ReestrRecord
*/
void init_Reestr(FILE* file, Reestr* structure)
	{
	char* Q = fread_string(file);
	structure->length = atoi(Q);
	free(Q);
	structure->reestr = (ReestrRecord**)calloc(structure->length, sizeof(ReestrRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		ReestrRecord* record = create_ReestrRecord();
		init_ReestrRecord(record, tmp);
		structure->reestr[i] = record;
		free(tmp);
		}
	}

/**
* \brief ‘ункци€ добавл€ет запись ReestrRecord
* \param structure структура Reestr, в которую будет добавл€тьс€ структура ReestrRecord
* \param record добавл€ема€ структура
* \return добавление структуры в структуру Reestr
*/
void add_ReestrRecord(Reestr* structure, ReestrRecord* record)
	{
	structure->length++;
	structure->reestr = (ReestrRecord**)realloc(structure->reestr, structure->length * sizeof(ReestrRecord*));
	structure->reestr[structure->length - 1] = record;
	}

/**
* \brief ‘ункци€ освобождает пам€ть Reestr
* \param structure структура, пам€ть которой будет освобождатьс€
* \return освобожденна€ пам€ть массива структур Reestr
*/
void delete_Reestr(Reestr* structure)
	{
	for (int i = 0; i < structure->length; i++)
		delete_ReestrRecord(structure->reestr[i]);
	free(structure->reestr);
	free(structure);
	}