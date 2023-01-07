#ifndef TABLERECORDARR_H
#define TABLERECORDARR_H

#include "TableRecord.h"
#include <stdio.h>

typedef struct TableRecordArr
    {
    TableRecord** table_record_arr;
    size_t size;
    } TableRecordArr;

TableRecordArr* create_TableRecordArr();
void init_TableRecordArr(TableRecordArr*);
void push_to_TableRecordArr(TableRecord*, TableRecordArr*);
void delete_TableRecordArr(TableRecordArr*);

#endif