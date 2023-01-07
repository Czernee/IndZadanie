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

TableRecordArr* create_OutputDetail()
	{
	return (TableRecordArr*)calloc(1, sizeof(TableRecordArr));
	}

void init_OutputDetail(TableRecord* record, Catalog* catalog, Reestr* reestr)
	{
	FILE* freestr = search_Table(get_InputRecord_month(input->input[0]), get_InputRecord_year(input->input[0]));
	// менять
	output->FamilyIO = (char*)calloc(strlen(input->input[0]->FamilyIO) + 1, sizeof(char));
	output->Month = (char*)calloc(strlen(input->input[0]->Month) + 1, sizeof(char));
	output->Year = (char*)calloc(strlen(input->input[0]->Year) + 1, sizeof(char));
	set_Output_FamilyIO(output, input->input[0]->FamilyIO);
	set_Output_Month(output, input->input[0]->Month);
	set_Output_Year(output, input->input[0]->Year);
	if (!check_file(ftable))
		{
		strcpy(output->DetailNum_s, "Error");
		output->DetailNum = 0;
		}
	else
		{
		Table* table = create_Table();
		init_Table(ftable, table);
		TableRecordArr* table_arr = create_TableRecordArr();
		init_TableRecordArr(table_arr);
		for (int i = 0; i < table->length; i++)
			{
			if (!strcmp(table->table[i]->FamilyIO, input->input[0]->FamilyIO))
				{
				push_to_TableRecordArr(table->table[i], table_arr);
				}
			}
		}
	}