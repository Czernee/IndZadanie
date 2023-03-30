#include "InputRecord.h"
#include "Functions.h"
#include <stdlib.h>
#include <string.h>

/**
* \brief Выделяет память и создает структуру InputRecord (запись файла inputTT.txt)
* \return выделение места под структуру InputRecord
*/
InputRecord* create_InputRecord()
	{
	return (InputRecord*)calloc(1, sizeof(InputRecord));
	}

/**
* \brief Функция "инициализирует" структуру
* \param structure структура, полям которой будут присваиваться значения
* \param str строка файла inputTT.txt
* \return инициализированная структура InputRecord
*/
void init_InputRecord(InputRecord* structure, char* str)
	{
	//выделение места для фамилии и иницалов преподавателей
	structure->Keyword = (char*)calloc(0, sizeof(char));
	structure->FamilyIO = (char*)calloc(0, sizeof(char));
	structure->Month = (char*)calloc(0, sizeof(char));
	structure->Year = (char*)calloc(0, sizeof(char));
	//info для всех полей InputRecord (записи строки input.txt)
	char** info = separate_InputRecord_string(str);
	char* info2_copy = (char*)calloc(strlen(info[2]) + 1, sizeof(char));
	strcpy(info2_copy, info[2]);
	char** date = separate_date(info2_copy);
	set_InputRecord_keyword(structure, info[0]);
	set_InputRecord_familyio(structure, info[1]);
	set_InputRecord_month(structure, date[0]);
	set_InputRecord_year(structure, date[1]);
	for (int i = 0; i < 2; i++)
		free(date[i]);
	for (int i = 0; i < 3; i++)
		free(info[i]);
	free(info);
	free(date);
	free(info2_copy);
	}	

/**
* \brief Функция возвращает ключевое слово inputTT.txt
* \param structure структура, краткое название которой нужно взять
* \return краткое название программы записи inputTT.txt
*/
char* get_InputRecord_keyword(InputRecord* structure)
	{
	return structure->Keyword;
	}

/**
* \brief Функция возвращает фамилию и инициалы преподавателя записи inputTT.txt
* \param structure структура, фамилию и инициалы преподавателя которой нужно взять
* \return фамилиия и инициалы преподавателя файла inputTT.txt
*/
char* get_InputRecord_familyio(InputRecord* structure)
	{
	return structure->FamilyIO;
	}

/**
* \brief Функция возвращает месяц расчетного периода записи inputTT.txt
* \param structure структура, месяц расчетного периода которой нужно взять
* \return месяц расчетного периода файла inputTT.txt
*/
char* get_InputRecord_month(InputRecord* structure)
	{
	return structure->Month;
	}

/**
* \brief Функция возвращает год расчетного периода записи inputTT.txt
* \param structure структура, год расчетного периода которой нужно взять
* \return год расчетного периода файла inputTT.txt
*/
char* get_InputRecord_year(InputRecord* structure)
	{
	return structure->Year;
	}

/**
* \brief Функция присваивает ключевое слово в структуре
* \param structure структура, которой нужно присвоить ключевое слово
* \param Keyword ключевое слово
* \return присвоенное ключевое слово
*/
void set_InputRecord_keyword(InputRecord* structure, char* Keyword)
	{
	structure->Keyword = (char*)realloc(structure->Keyword, (strlen(Keyword) + 1) * sizeof(char));
	strcpy(structure->Keyword, Keyword);
	}

/**
* \brief Функция присваивает фамилию и инициалы преподавателя в структуре
* \param structure структура, которой нужно присвоить  фамилию и инициалы преподавателя
* \param FamilyIO фамилия и инициалы преподавателя
* \return присвоенные фамилия и инициалы преподавателя
*/
void set_InputRecord_familyio(InputRecord* structure, char* FamilyIO)
	{
	structure->FamilyIO = (char*)realloc(structure->FamilyIO, (strlen(FamilyIO) + 1) * sizeof(char));
	strcpy(structure->FamilyIO, FamilyIO);
	}

/**
* \brief Функция присваивает месяц расчетного периода в структуре
* \param structure структура, которой нужно присвоить месяц расчетного периода
* \param Month месяц расчетного периода
* \return присвоенный месяц расчетного периода
*/
void set_InputRecord_month(InputRecord* structure, char* Month)
	{
	structure->Month = (char*)realloc(structure->Month, (strlen(Month) + 1) * sizeof(char));
	strcpy(structure->Month, Month);
	}

/**
* \brief Функция присваивает год расчетного периода в структуре
* \param structure структура, которой нужно присвоить год расчетного периода
* \param Year год расчетного периода
* \return присвоенный год расчетного периода
*/
void set_InputRecord_year(InputRecord* structure, char* Year)
	{
	structure->Year = (char*)realloc(structure->Year, (strlen(Year) + 1) * sizeof(char));
	strcpy(structure->Year, Year);
	}

/**
* \brief Функция делит запись inputTT.txt на части и присваивает их значения соответствующим полям
* \param str строка, которую нужно поделить
* \return поделенная строка inputTT.txt и присвоенные значения полям
*/
char** separate_InputRecord_string(char* str)
	{
	char** info = (char**)calloc(3, sizeof(char*));
	char* Keyword = strtok(str, " ");
	info[0] = (char*)calloc(strlen(Keyword) + 1, sizeof(char));
	char* FamilyIO = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(FamilyIO) + 1, sizeof(char));
	char* Date = strtok(NULL, "");
	info[2] = (char*)calloc(strlen(Date) + 1, sizeof(char));
	strcpy(info[0], Keyword);
	strcpy(info[1], FamilyIO);
	strcpy(info[2], Date);
	return info;
	}

/**
* \brief Функция освообждает память структуры InputRecord
* \param structure структура, которую нужно поделить
* \return освобожденная память структуры InputRecord
*/
void delete_InputRecord(InputRecord* structure)
	{
	free(structure->Keyword);
	free(structure->FamilyIO);
	free(structure->Month);
	free(structure->Year);
	free(structure);
	}