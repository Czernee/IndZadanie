#include "ReestrRecordArr.h"
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------
// Функция создает массив записей реестра
ReestrRecordArr* create_ReestrRecordArr()
    {
    return (ReestrRecordArr*)calloc(1, sizeof(ReestrRecordArr));
    }

//---------------------------------------------------------------------
// Функция "инициализриует" массив записей реестра
void init_ReestrRecordArr(ReestrRecordArr* to_construct)
    {
    to_construct->size = 0;
    to_construct->reestr_record_arr = calloc(1, sizeof(to_construct->reestr_record_arr));
    }

//---------------------------------------------------------------------
// Функция ...
void push_to_ReestrRecordArr(ReestrRecord* to_push, ReestrRecordArr* ReestrRecordArr)
    {
    ReestrRecordArr->size++;
    ReestrRecordArr->reestr_record_arr = (ReestrRecord**)realloc(ReestrRecordArr->reestr_record_arr, ReestrRecordArr->size * sizeof(ReestrRecord*));
    ReestrRecordArr->reestr_record_arr[ReestrRecordArr->size - 1] = to_push;
    }

//---------------------------------------------------------------------
// Функция освобождает память массива записей реестра
void delete_ReestrRecordArr(ReestrRecordArr* structure)
    {
    free(structure->reestr_record_arr);
    free(structure);
    }