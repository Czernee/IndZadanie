#include "TableRecord.h"
#include "Functions.h"
#include "Table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//---------------------------------------------------------------------------------
// ������� ������� ������ �������� TableRecord (������ ������� ����� tab_MM_YYYY.txt)
Table* create_Table()
	{
	return (Table*)calloc(1, sizeof(Table));
	}

//---------------------------------------------------------------------------------
// ������� "��������������" ������ ��������
// ��. ������: ���� � ��������, ���������, �� ��������� ������� ����� ����������� ������
void init_Table(FILE* file, Table* structure)
	{
	char* L = fread_string(file);
	structure->length = atoi(L);
	structure->table = (TableRecord**)calloc(structure->length, sizeof(TableRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		TableRecord* record = create_TableRecord();
		init_TableRecord(record, tmp);
		structure->table[i] = record;
		}
	}

//---------------------------------------------------------------------------------
// ������� ��������� ������ TableRecord
// ��. ������: ���������, � ������� ����������� ������, ������
void add_TableRecord(Table* structure, TableRecord* record)
	{
	structure->length++;
	structure->table = (TableRecord**)realloc(structure->table, structure->length * sizeof(TableRecord*));
	structure->table[structure->length - 1] = record;
	}

FILE* search_Table(char* month, char* year)
	{
	char* tmp = (char*)calloc(16, sizeof(char));
	sprintf(tmp, "tab_%s_%s.txt", month, year);
	FILE* table = fopen(tmp, "r");
	check_file(table);
	free(tmp);
	return table;
	}

//---------------------------------------------------------------------------------
// ������� ����������� ������ Table
// ��. ������: ���������
void delete_Table(Table* structure)
	{
	for (int i = 0; i < structure->length; i++)
		delete_TableRecord(structure->table[i]);
	free(structure->table);
	free(structure);
	}