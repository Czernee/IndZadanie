#ifndef REESTRRECORD_H
#define REESTRRECORD_H

#include <stdio.h>
#include <stdlib.h>

/**
* \struct ReestrRecord
* \brief —одержит запись (строку) файла Reestr.txt
* \param ShortName краткое наименование программы
* \param RealizationBeginningMonth мес€ц начала реализации программы
* \param RealizationBeginningYear год начала реализации программы
* \param RealizationEndingMonth мес€ц окончани€ реализации программы
* \param RealizationEndingYear год окончани€ реализации программы
* \param Price стоимость обучени€ на программе в рубл€х
* \param StudentsAmount количество обучающихс€ на программе
* \param GroupsAmount количество групп на программе
*/

typedef struct ReestrRecord
	{
	char* ShortName;
	char* RealizationBeginningMonth;
	char* RealizationBeginningYear;
	char* RealizationEndingMonth;
	char* RealizationEndingYear;
	int Price;
	int StudentsAmount;
	int GroupsAmount;
	} ReestrRecord;

ReestrRecord* create_ReestrRecord();
void init_ReestrRecord(ReestrRecord* structure, char* str);
char* get_ReestrRecord_shortname(ReestrRecord* structure);
char* get_ReestrRecord_realization_beginning_month(ReestrRecord* structure);
char* get_ReestrRecord_realization_beginning_year(ReestrRecord* structure);
char* get_ReestrRecord_realization_ending_month(ReestrRecord* structure);
char* get_ReestrRecord_realization_ending_year(ReestrRecord* structure);
int get_ReestrRecord_price(ReestrRecord* structure);
int get_ReestrRecord_students_amount(ReestrRecord* structure);
int get_ReestrRecord_groups_amount(ReestrRecord* structure);
void set_ReestrRecord_shortname(ReestrRecord* structure, char* ShortName);
void set_ReestrRecord_realization_beginning_month(ReestrRecord* structure, char* RealizationBeginning);
void set_ReestrRecord_realization_beginning_year(ReestrRecord* structure, char* RealizationBeginning);
void set_ReestrRecord_realization_ending_month(ReestrRecord* structure, char* RealizationEnding);
void set_ReestrRecord_realization_ending_year(ReestrRecord* structure, char* RealizationEnding);
void set_ReestrRecord_price(ReestrRecord* structure, int Price);
void set_ReestrRecord_students_amount(ReestrRecord* structure, int StudentsAmount);
void set_ReestrRecord_groups_amount(ReestrRecord* structure, int GroupsAmount);
char** separate_ReestrRecord_string(char* str);
void delete_ReestrRecord(ReestrRecord* structure);

#endif