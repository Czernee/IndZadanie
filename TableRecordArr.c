#include <stdio.h>
#include <stdlib.h>
#include "TableRecordArr.h"

/**
* \brief Выделяет память и создает массив стуруктур TableRecordArr
* \return выделение места под массив структур TableRecordArr
*/
TableRecordArr* create_TableRecordArr()
    {
    return (TableRecordArr*)calloc(1, sizeof(TableRecordArr));
    }

/**
* \brief Функция "инициализирует" массив структур TableRecord
* \param to_construct массив структур, полям которой будут присваиваться значения
* \param str строка файла tab__MM_YYYY.txt
* \return инициализированные структуры TableRecord
*/
void init_TableRecordArr(TableRecordArr* to_construct)
    {
    to_construct->size = 0;
    to_construct->table_record_arr = calloc(1, sizeof(to_construct->table_record_arr));
    }

/**
* \brief Функция добавляет стрктуру TableRecord в TableRecordArr
* \param to_push добавляемая структура типа TableRecord
* \param TableRecordArr структура, в которую будет приниматься структура to_push
* \return добавление структуры в структуру TableRecordArr
*/
void push_to_TableRecordArr(TableRecord* to_push, TableRecordArr* TableRecordArr)
    {
    TableRecordArr->size++;
    TableRecordArr->table_record_arr = (TableRecord**)realloc(TableRecordArr->table_record_arr, TableRecordArr->size * sizeof(TableRecord*));
    TableRecordArr->table_record_arr[TableRecordArr->size - 1] = to_push;
    }

/**
* \brief Функция находит нужную запись по фамилии и инциалам
* \param table_arr структура Catalog, в которую будет добавляться структура CatalogRecord
* \param record добавляемая структура
* \param record добавляемая структура
* 
* \return добавление структуры\param record добавляемая структура в структуру Catalog
*/
void find_TableRecords_with_FamilyIO(TableRecordArr* table_arr,Table* table,Input* input,Catalog* catalog)
    {
    for (int i = 0; i < table->length; i++)
        {
        if (!strcmp(table->table[i]->FamilyIO, input->input[0]->FamilyIO))
            {
            if (check_S_aud(table->table[i],table,catalog))
                {
                push_to_TableRecordArr(table->table[i], table_arr);
                }
            }
        }
    }

/**
* \brief Функция освообждает память структуры TableRecordArr
* \param structure структура, память которой нужно освободить
* \return освобожденная память структуры TableRecordArr
*/
void delete_TableRecordArr(TableRecordArr* structure)
    {
    free(structure->table_record_arr);
    free(structure);
    }