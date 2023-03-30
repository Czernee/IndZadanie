#define _CRT_SECURE_NO_WARNINGS
#include "ReestrRecordArr.h"
#include <stdio.h>
#include <stdlib.h>

/**
* \brief Выделяет память и создает массив стуруктур ReestrRecord
* \return выделение места под массив структур ReestrRecord
*/
ReestrRecordArr* create_ReestrRecordArr()
    {
    return (ReestrRecordArr*)calloc(1, sizeof(ReestrRecordArr));
    }

/**
* \brief Функция "инициализирует" массив структур ReestrRecord
* \param to_construct массив структур, полям которой будут присваиваться значения
* \param str строка файла Reestr.txt
* \return инициализированные структуры ReestrRecord
*/
void init_ReestrRecordArr(ReestrRecordArr* to_construct)
    {
    to_construct->size = 0;
    to_construct->reestr_record_arr = calloc(1, sizeof(to_construct->reestr_record_arr));
    }

/**
* \brief Функция добавляет стрктуру ReestrRecord в ReestrRecordArr
* \param to_push добавляемая структура типа ReestrRecord
* \param ReestrRecordArr структура, в которую будет приниматься структура to_push
* \return добавление структуры в структуру ReestrRecordArr
*/
void push_to_ReestrRecordArr(ReestrRecord* to_push, ReestrRecordArr* ReestrRecordArr)
    {
    ReestrRecordArr->size++;
    ReestrRecordArr->reestr_record_arr = (ReestrRecord**)realloc(ReestrRecordArr->reestr_record_arr, ReestrRecordArr->size * sizeof(ReestrRecord*));
    ReestrRecordArr->reestr_record_arr[ReestrRecordArr->size - 1] = to_push;
    }

/**
* \brief Функция находит нужную запись по короткому наименованию
* \param structure структура Catalog, в которую будет добавляться структура CatalogRecord
* \param record добавляемая структура
* \return добавление структуры в структуру Catalog
*/
void find_ReestrRecords_with_ShortName(ReestrRecordArr* reestr_arr,TableRecordArr* table_arr, Reestr* reestr,Input* input)
    {
    for (int i = 0; i < reestr->length; i++)
        {
        for (int j = 0; j < table_arr->size; j++)
            {
            if (!strcmp(get_ReestrRecord_shortname(reestr->reestr[i]), get_TableRecord_shortname(table_arr->table_record_arr[j])))
                {
                int realization_beginning_month = atoi(get_ReestrRecord_realization_beginning_month(reestr->reestr[i]));
                int realization_beginning_year = atoi(get_ReestrRecord_realization_beginning_year(reestr->reestr[i]));
                int realization_ending_month = atoi(get_ReestrRecord_realization_ending_month(reestr->reestr[i]));
                int realization_ending_year = atoi(get_ReestrRecord_realization_ending_year(reestr->reestr[i]));
                int input_month = atoi(get_InputRecord_month(input->input[0]));
                int input_year = atoi(get_InputRecord_year(input->input[0]));
                if ( (input_year > realization_beginning_year && input_year < realization_ending_year) ||
                (input_year == realization_beginning_year && input_month >= realization_beginning_month) ||
                (input_year == realization_ending_year && input_month <= realization_ending_month))
                    {
                    push_to_ReestrRecordArr(reestr->reestr[i], reestr_arr);
                    }
                }
            }
        }
    }

/**
* \brief Функция освообждает память структуры ReestrRecordArr
* \param structure структура, память которой нужно освободить
* \return освобожденная память структуры ReestrRecordArr
*/
void delete_ReestrRecordArr(ReestrRecordArr* structure)
    {
    free(structure->reestr_record_arr);
    free(structure);
    }