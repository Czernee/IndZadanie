#ifndef OUTPUTDETAIL_H
#define OUTPUTDETAIL_H

#include "TableRecordArr.h"
#include "Catalog.h"
#include "Reestr.h"

typedef struct OutputDetail
	{
	char* ProgramName;
	int NumH;
	int S_aud;
	double PH;
	double SumProg;
	} OutputDetail;

TableRecordArr* create_OutputDetail();	 
void init_OutputDetail(TableRecord* record, Catalog* catalog, Reestr* reestr);

#endif 
