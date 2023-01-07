#ifndef OUTPUT_H
#define OUTPUT_H

#include "OutputDetail.h"

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
void print_Output(Output* structure);

#endif 

