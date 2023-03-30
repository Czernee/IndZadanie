#include "CatalogRecord.h"
#include "Functions.h"
#include <stdlib.h>
#include <string.h>

/**
* \brief Выделяет память и создает структуру CatalogRecord (запись файла Catalog.txt)
* \return выделение места под структуру CatalogRecord
*/
CatalogRecord* create_CatalogRecord()
	{
	return (CatalogRecord*)calloc(1, sizeof(CatalogRecord));
	}

/**
* \brief Функция "инициализирует" структуру
* \param structure структура, полям которой будут присваиваться значения
* \param str строка файла Catalog.txt
* \return инициализированная структура CatalogRecord
*/
void init_CatalogRecord(CatalogRecord* structure, char* str)
	{
	//выделение места для имен
	structure->ShortName = (char*)calloc(0, sizeof(char));
	structure->FullName = (char*)calloc(0, sizeof(char));
	//info для всех полей CatalogRecord (записи строки Catalog.txt)
	char** info = separate_CatalogRecord_string(str);
	set_CatalogRecord_shortname(structure, info[0]);
	set_CatalogRecord_hours(structure, atoi(info[1]));
	set_CatalogRecord_aud_hours(structure, atoi(info[2]));
	set_CatalogRecord_fullname(structure, info[3]);
	for (int i = 0; i < 4; i++)
		free(info[i]);
	free(info);
	}

/**
* \brief Функция возвращает краткое название программы записи Catalog.txt
* \param structure структура, краткое название которой нужно взять
* \return краткое название программы записи Catalog.txt
*/
char* get_CatalogRecord_shortname(CatalogRecord* structure)
	{
	return structure->ShortName;
	}

/**
* \brief Функция возвращает общее количество часов по программе записи Catalog.txt
* \param structure структура, общее количество часов по программе которой нужно взять
* \return общее количество часов Catalog.txt
*/
int get_CatalogRecord_hours(CatalogRecord* structure)
	{
	return structure->Hours;
	}

/**
* \brief Функция возвращает количество часов аудиторных занятий записи Catalog.txt
* \param structure структура, количество часов аудиторных занятий которой нужно взять
* \return количество часов аудиторных занятий записи Catalog.txt
*/
int get_CatalogRecord_aud_hours(CatalogRecord* structure)
	{
	return structure->AudHours;
	}

/**
* \brief Функция возвращаетполное наименование программы записи Catalog.txt
* \param structure структура, полное наименование программы которой нужно взять
* \return полное наименование программы записи Catalog.txt
*/
char* get_CatalogRecord_fullname(CatalogRecord* structure)
	{
	return structure->FullName;
	}

/**
* \brief Функция присваивает имя короткому имени программы в структуре
* \param structure структура, которой нужно присвоить краткое имя
* \param ShortName присваиваемое краткое имя
* \return присвоенное краткое имя
*/
void set_CatalogRecord_shortname(CatalogRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

/**
* \brief Функция присваивает общее количество часов по программе в структуре
* \param structure структура, которой нужно присвоить общее количество часов по программе
* \param Hours присваиваемое общее количество часов по программе
* \return присвоенное общее количество часов по программе
*/
void set_CatalogRecord_hours(CatalogRecord* structure, int Hours)
	{
	structure->Hours = Hours;
	}

/**
* \brief Функция присваивает количество часов аудиторных занятий в структуре
* \param structure структура, которой нужно присвоить количество часов аудиторных занятий
* \param AudHours присваиваемое количество часов аудиторных занятий
* \return присвоенное количество часов аудиторных занятий
*/
void set_CatalogRecord_aud_hours(CatalogRecord* structure, int AudHours)
	{
	structure->AudHours = AudHours;
	}

/**
* \brief Функция присваивает полное наименование программы в структуре
* \param structure структура, которой нужно присвоить полное наименование программы
* \param FullName присваиваемое полное наименование программы
* \return присвоенное полное наименование программы
*/
void set_CatalogRecord_fullname(CatalogRecord* structure, char* FullName)
	{
	structure->FullName = (char*)realloc(structure->FullName, (strlen(FullName) + 1) * sizeof(char));
	strcpy(structure->FullName, FullName);
	}

/**
* \brief Функция делит запись Catalog.txt на части и присваивает их значения соответствующим полям
* \param str строка, которую нужно поделить
* \return поделенная строка Catalog.txt и присвоенные значения полям
*/
char** separate_CatalogRecord_string(char* str)
	{
	char** info = (char**)calloc(4, sizeof(char*));
	char* ShortName = strtok(str, " ");
	info[0] = (char*)calloc(strlen(ShortName) + 1, sizeof(char));
	char* Hours = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(Hours) + 1, sizeof(char));
	char* AkademHours = strtok(NULL, " ");
	info[2] = (char*)calloc(strlen(AkademHours) + 1, sizeof(char));
	char* FullName = strtok(NULL, "");
	info[3] = (char*)calloc(strlen(FullName) + 1, sizeof(char));
	strcpy(info[0], ShortName);
	strcpy(info[1], Hours);
	strcpy(info[2], AkademHours);
	strcpy(info[3], FullName);
	return info;
	}

/**
* \brief Функция освообждает память структуры CatalogRecord
* \param structure структура, память которой нужно освободить
* \return освобожденная память структуры CatalogRecord
*/
void delete_CatalogRecord(CatalogRecord* structure)
	{
	free(structure->ShortName);
	free(structure->FullName);
	free(structure);
	}
