#include "Output.h"
#include "Catalog.h"
#include "Reestr.h"
#include "Table.h"
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Output* create_output()
	{
	return (Output*)calloc(1, sizeof(Output));
	}

void init_Output(Catalog* catalog, Reestr* reestr, Input* input, Output* output)
	{
	FILE* table = search_Table(get_InputRecord_month(input->input[0]), get_InputRecord_year(input->input[0]));
	strcpy(output->FamilyIO, input->input[0]->FamilyIO);
	strcpy(output->Month, input->input[0]->Month);
	strcpy(output->Year, input->input[0]->Year);
	if (!check_file(table))
		{
		strcpy(output->DetailNum_s, "Error");
		output->DetailNum = 0;
		}
	else
		{

		}
	}