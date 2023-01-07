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

Output* create_Output()
	{
	return (Output*)calloc(1, sizeof(Output));
	}

void init_Output(Catalog* catalog, Reestr* reestr, Input* input, Output* output)
	{
	FILE* ftable = search_Table(get_InputRecord_month(input->input[0]), get_InputRecord_year(input->input[0]));
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

void set_Output_FamilyIO(Output* structure, char* FamilyIO)
	{
	structure->FamilyIO = (char*)realloc(structure->FamilyIO, (strlen(FamilyIO) + 1) * sizeof(char));
	strcpy(structure->FamilyIO, FamilyIO);
	}

void set_Output_Month(Output* structure, char* Month)
	{
	structure->Month = (char*)realloc(structure->Month, (strlen(Month) + 1) * sizeof(char));
	strcpy(structure->Month, Month);
	}

void set_Output_Year(Output* structure, char* Year)
	{
	structure->Year = (char*)realloc(structure->Year, (strlen(Year) + 1) * sizeof(char));
	strcpy(structure->Year, Year);
	}

void set_Output_Result(Output* structure, double Result)
	{
	structure->Result = Result;
	}

void set_Output_DetailNum_s(Output* structure, char* DetailNum_s)
	{
	structure->DetailNum_s = (char*)realloc(structure->DetailNum_s, (strlen(DetailNum_s) + 1) * sizeof(char));
	strcpy(structure->DetailNum_s, DetailNum_s);
	}