#define _CRT_SECURE_NO_WARNINGS
#include "ReestrRecordArr.h"
#include <stdio.h>
#include <stdlib.h>

/**
* \brief �������� ������ � ������� ������ ��������� ReestrRecord
* \return ��������� ����� ��� ������ �������� ReestrRecord
*/
ReestrRecordArr* create_ReestrRecordArr()
    {
    return (ReestrRecordArr*)calloc(1, sizeof(ReestrRecordArr));
    }

/**
* \brief ������� "��������������" ������ �������� ReestrRecord
* \param to_construct ������ ��������, ����� ������� ����� ������������� ��������
* \param str ������ ����� Reestr.txt
* \return ������������������ ��������� ReestrRecord
*/
void init_ReestrRecordArr(ReestrRecordArr* to_construct)
    {
    to_construct->size = 0;
    to_construct->reestr_record_arr = calloc(1, sizeof(to_construct->reestr_record_arr));
    }

/**
* \brief ������� ��������� �������� ReestrRecord � ReestrRecordArr
* \param to_push ����������� ��������� ���� ReestrRecord
* \param ReestrRecordArr ���������, � ������� ����� ����������� ��������� to_push
* \return ���������� ��������� � ��������� ReestrRecordArr
*/
void push_to_ReestrRecordArr(ReestrRecord* to_push, ReestrRecordArr* ReestrRecordArr)
    {
    ReestrRecordArr->size++;
    ReestrRecordArr->reestr_record_arr = (ReestrRecord**)realloc(ReestrRecordArr->reestr_record_arr, ReestrRecordArr->size * sizeof(ReestrRecord*));
    ReestrRecordArr->reestr_record_arr[ReestrRecordArr->size - 1] = to_push;
    }

/**
* \brief ������� ������� ������ ������ �� ��������� ������������
* \param structure ��������� Catalog, � ������� ����� ����������� ��������� CatalogRecord
* \param record ����������� ���������
* \return ���������� ��������� � ��������� Catalog
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
* \brief ������� ����������� ������ ��������� ReestrRecordArr
* \param structure ���������, ������ ������� ����� ����������
* \return ������������� ������ ��������� ReestrRecordArr
*/
void delete_ReestrRecordArr(ReestrRecordArr* structure)
    {
    free(structure->reestr_record_arr);
    free(structure);
    }