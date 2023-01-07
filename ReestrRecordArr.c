#include "ReestrRecordArr.h"
#include <stdio.h>
#include <stdlib.h>

ReestrRecordArr* create_ReestrRecordArr()
    {
    return (ReestrRecordArr*)calloc(1, sizeof(ReestrRecordArr));
    }

void init_ReestrRecordArr(ReestrRecordArr* to_construct)
    {
    to_construct->size = 0;
    to_construct->reestr_record_arr = calloc(1, sizeof(to_construct->reestr_record_arr));
    }

void push_to_ReestrRecordArr(ReestrRecord* to_push, ReestrRecordArr* ReestrRecordArr)
    {
    ReestrRecordArr->size++;
    ReestrRecordArr->reestr_record_arr = (ReestrRecord**)realloc(ReestrRecordArr->reestr_record_arr, ReestrRecordArr->size * sizeof(ReestrRecord*));
    ReestrRecordArr->reestr_record_arr[ReestrRecordArr->size - 1] = to_push;
    }

void delete_output_detail_arr(ReestrRecordArr* structure)
    {
    free(structure->reestr_record_arr);
    free(structure);
    }