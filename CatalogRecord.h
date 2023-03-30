#ifndef CATALOGRECORD_H
#define CATALOGRECORD_H

#include <stdlib.h>
#include <string.h>

/**
* \struct CatalogRecord
* \brief Содержит запись (строку) файла Catalog.txt
* \param ShortName краткое наименование программы
* \param Hours общее количество часов по программе
* \param AudHours количество часов аудиторных занятий
* \param FullName полное наименование программы
*/

typedef struct CatalogRecord
	{
	char* ShortName;
	int Hours;
	int AudHours;
	char* FullName;
	} CatalogRecord;

CatalogRecord* create_CatalogRecord();
void init_CatalogRecord(CatalogRecord* structure, char* str);
char* get_CatalogRecord_shortname(CatalogRecord* structure);
int get_CatalogRecord_hours(CatalogRecord* structure);
int get_CatalogRecord_aud_hours(CatalogRecord* structure);
char* get_CatalogRecord_fullname(CatalogRecord* structure);
void set_CatalogRecord_shortname(CatalogRecord* structure, char* ShortName);
void set_CatalogRecord_hours(CatalogRecord* structure, int Hours);
void set_CatalogRecord_aud_hours(CatalogRecord* structure, int AudHours);
void set_CatalogRecord_fullname(CatalogRecord* structure, char* FullName);
char** separate_CatalogRecord_string(char* str);
void delete_CatalogRecord(CatalogRecord* structure);


#endif 
