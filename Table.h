#ifndef TABLE_H
#define TABLE_H

#include "TableRecord.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Table
	{
	TableRecord** table;
	size_t length;
	} Table;

Table* create_Table();
void init_Table(FILE* file, Table* structure);
void add_TableRecord(Table* structure, TableRecord*);
int if_exist_Table(char* month, char* year);
FILE* search_Table(char* name);
void delete_Table(Table* structure);

#endif 