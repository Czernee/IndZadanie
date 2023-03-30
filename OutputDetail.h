#ifndef OUTPUTDETAIL_H
#define OUTPUTDETAIL_H

#include "TableRecordArr.h"
#include "Catalog.h"
#include "Reestr.h"
#include "Table.h"
#include <string.h>

/**
* \brief Содержит данные для вывода в файл outputTT.txt
* \param ProgramName краткое наименование программы
* \param NumH количество часов, отработанных преподавателем по программе в расчетный период
* \param S_aud общее количество аудиторных часов по образовательной программе в расчетный период
* \param PH почасовая ставка оплаты по программе в расчетный период в формате "рубли.копейки"
* \param SumProg сумма оплаты преподавателю по программе в расчетный период в формате "рубли.копейки"
*/

typedef struct OutputDetail
	{
	char* ProgramName;
	int NumH;
	int S_aud;
	double PH;
	double SumProg;
	} OutputDetail;

OutputDetail* create_OutputDetail();
void init_OutputDetail(OutputDetail* output_detail, TableRecord* table_record, ReestrRecord* reestr_record, Catalog* catalog, Table* table);
void delete_OutputDetail(OutputDetail* output_detail);




#endif 
