#ifndef OUTPUT_H
#define OUTPUT_H

#include "Output.h"
#include "Catalog.h"
#include "Reestr.h"
#include "Table.h"
#include "Input.h"
#include "OutputDetail.h"
#include "TableRecordArr.h"
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \struct Output
* \brief Структура для хранения данных для вывода
* \param FamilyIO фамилия и инициалы преподавателя
* \param Month месяц расчетного периода программы
* \param Year год расчетного периода программы
* \param Result рассчитанное итоговое значение
* \param DetailNum_s строка детализации
* \param DetailNum количество строк детализации
* \param Details массив структур OuputDetail
*/

typedef struct Output
	{
	char* FamilyIO;
	char* Month;
	char* Year;
	double Result;
	char* DetailNum_s;
	size_t DetailNum;
	OutputDetail** Details;
	} Output;

Output* create_Output();
void init_Output(Catalog* catalog, Reestr* reestr, Input* input, Output* output);
void set_Output_FamilyIO(Output* structure, char* FamilyIO);
void set_Output_Month(Output* structure, char* Month);
void set_Output_Year(Output* structure, char* Year);
void set_Output_Result(Output* structure, double Result);
void set_Output_DetailNum_s(Output* structure, char* DetailNum_s);
void push_to_Details(OutputDetail*, Output*);
void print_Output(Output* structure);
void delete_Output(Output* structure);

#endif 

