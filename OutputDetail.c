#include "Output.h"
#include "Catalog.h"
#include "Reestr.h"
#include "Table.h"
#include "Input.h"
#include "OutputDetail.h"
#include "TableRecordArr.h"
#include "ReestrRecordArr.h"
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
* \brief Выделяет память и создает структуру OuputDetail (запись файла inputTT.txt)
* \return выделение места под структуру InputRecord
*/
OutputDetail* create_OutputDetail()
	{
	return (OutputDetail*)calloc(1, sizeof(OutputDetail));
	}


/**
* \brief "инициализирует" структуру OutputDetail
* \param output_detail инициализируемая структура
* \param table_record структура, на основании которой инициализируется output_detail
* \param reestr_record структура, на основании которой инициализируется output_detail
* \param catalog структура, на основании которой инициализируется output_detail
* \param table структура, на основании которой инициализируется output_detail
* \return "инициализация" структуры Output
*/
void init_OutputDetail(OutputDetail* output_detail, TableRecord* table_record, ReestrRecord* reestr_record, Catalog* catalog, Table* table)
	{
	CatalogRecord* catalog_record = get_CatalogRecord_by_shortname(get_TableRecord_shortname(table_record), catalog);

	output_detail->ProgramName = (char**)calloc(strlen(table_record->ShortName) + 1, sizeof(char));
	strcpy(output_detail->ProgramName, table_record->ShortName);
	output_detail->NumH = table_record->AudHours;

	output_detail->S_aud = get_S_aud_month(get_TableRecord_shortname(table_record),table);

	int Ti = get_ReestrRecord_price(reestr_record);
	int Ni = get_ReestrRecord_students_amount(reestr_record);
	int Vi = Ti * Ni;

	double K_fot = catalog->K_fot;
	double Vi_fot = Vi * (K_fot/100);

	int Ngr = get_ReestrRecord_groups_amount(reestr_record);
	int S_aud = get_CatalogRecord_aud_hours(catalog_record);

	double PH = Vi_fot/(Ngr*S_aud);
		
	output_detail->PH = floor(PH*100)/100;
	output_detail->SumProg = (floor(PH*100)/100) * output_detail->NumH;
	}

/**
* \brief Функция освобождает память OutputDetail
* \param output_detail структура, память которой будет освобождаться
* \return освобожденная память структуры OutputDetail
*/
void delete_OutputDetail(OutputDetail* output_detail)
	{
	free(output_detail->ProgramName);
	free(output_detail);
	}