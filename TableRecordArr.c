#include "TableRecordArr.h"
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------
// Функция создает массив записей табеля
TableRecordArr* create_TableRecordArr()
    {
    return (TableRecordArr*)calloc(1, sizeof(TableRecordArr));
    }

//---------------------------------------------------------------------
// Функция "инициализриует" массив записей табеля
void init_TableRecordArr(TableRecordArr* to_construct)
    {
    to_construct->size = 0;
    to_construct->table_record_arr = calloc(1, sizeof(to_construct->table_record_arr));
    }

//---------------------------------------------------------------------
// Функция ...
void push_to_TableRecordArr(TableRecord* to_push, TableRecordArr* TableRecordArr)
    {
    TableRecordArr->size++;
    TableRecordArr->table_record_arr = (TableRecord**)realloc(TableRecordArr->table_record_arr, TableRecordArr->size * sizeof(TableRecord*));
    TableRecordArr->table_record_arr[TableRecordArr->size - 1] = to_push;
    }

//---------------------------------------------------------------------
// Функция освобождает память массива записей табеля
void delete_output_detail_arr(TableRecordArr* structure)
    {
    free(structure->table_record_arr);
    free(structure);
    }