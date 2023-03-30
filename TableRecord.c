#include "TableRecord.h"
#include "Functions.h"
#include <stdlib.h>
#include <string.h>

/**
* \brief Выделяет память и создает структуру TableRecord (запись файла tab_MM_YYYY.txt)
* \return выделение места под структуру TableRecord
*/
TableRecord* create_TableRecord()
	{
	return (TableRecord*)calloc(1, sizeof(TableRecord));
	}

/**
* \brief Функция "инициализирует" структуру
* \param structure структура, полям которой будут присваиваться значения
* \param str строка файла tab_MM_YYY.txt
* \return инициализированная структура TableRecord
*/
void init_TableRecord(TableRecord* structure, char* str)
	{
	//выделение места для имен
	structure->FamilyIO = (char*)calloc(0, sizeof(char));
	structure->ShortName = (char*)calloc(0, sizeof(char));
	//info для всех полей TableRecord (записи строки Table.txt)
	char** info = separate_TableRecord_string(str);
	set_TableRecord_familyio(structure, info[0]);
	set_TableRecord_shortname(structure, info[1]);
	set_TableRecord_audhours(structure, atoi(info[2]));
	for (int i = 0; i < 3; i++)
		free(info[i]);
	free(info);
	}

/**
* \brief Функция возвращает фамилию и инициалы записи tab_MM_YYYY.txt
* \param structure структура, фамилию и инициалы которой нужно взять
* \return фамилия и инициалы записи tab_MM_YYYY.txt
*/
char* get_TableRecord_famiilyio(TableRecord* structure)
	{
	return structure->FamilyIO;
	}

/**
* \brief Функция возвращает краткое название программы записи tab_MM_YYYY.txt
* \param structure структура, краткое название которой нужно взять
* \return краткое название программы записи tab_MM_YYYY.txt
*/
char* get_TableRecord_shortname(TableRecord* structure)
	{
	return structure->ShortName;
	}

/**
* \brief Функция возвращает количество аудиторных часов, отработанных на программе за месяц записи tab_MM_YYYY.txt
* \param structure структура, количество аудиторных часов которой нужно взять
* \return количество аудиторных часов записи tab_MM_YYYY.txt
*/
int get_TableRecord_audhours(TableRecord* structure)
	{
	return structure->AudHours;
	}

/**
* \brief Функция присваивает фамилию и инициалы в структуре
* \param structure структура, которой нужно присвоить фамилию и инициалы 
* \return присвоенные фамилию и инициалы
*/
void set_TableRecord_familyio(TableRecord* structure, char* FamilyIO)
	{
	structure->FamilyIO = (char*)realloc(structure->FamilyIO, (strlen(FamilyIO) + 1) * sizeof(char));
	strcpy(structure->FamilyIO, FamilyIO);
	}

/**
* \brief Функция присваивает имя короткому наименованию программы в структуре
* \param structure структура, короткому наименованию которой нужно присвоить имя
* \return присвоенное короткое наименование
*/
void set_TableRecord_shortname(TableRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

/**
* \brief Функция присваивает количество аудиторных часов, отработанных на программе за месяц в структуре
* \param structure структура, которой нужно присвоить количество аудиторных часов
* \return присвоенное количество аудиторных часов
*/
void set_TableRecord_audhours(TableRecord* structure, int AudHours)
	{
	structure->AudHours = AudHours;
	}

/**
* \brief Функция делит запись tab_MM_YYYY.txt на части и присваивает их значения соответствующим полям
* \param str строка, которую нужно поделить
* \return поделенная строка tab_MM_YYYY.txt и присвоенные значения полям
*/
char** separate_TableRecord_string(char* str)
	{
	char** info = (char**)calloc(4, sizeof(char*));
	char* FamilyIO = strtok(str, " ");
	info[0] = (char*)calloc(strlen(FamilyIO) + 1, sizeof(char));
	char* ShortName = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(ShortName) + 1, sizeof(char));
	char* AudHours = strtok(NULL, "");
	info[2] = (char*)calloc(strlen(AudHours) + 1, sizeof(char));
	strcpy(info[0], FamilyIO);
	strcpy(info[1], ShortName);
	strcpy(info[2], AudHours);
	return info;
	}

/**
* \brief Функция освообждает память структуры ReestrRecord
* \param structure структура, память которой нужно освободить
* \return освобожденная память структуры ReestrRecord
*/
void delete_TableRecord(TableRecord* structure)
	{
	free(structure->FamilyIO);
	free(structure->ShortName);
	free(structure);
	}