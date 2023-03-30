#include "ReestrRecord.h"
#include "Functions.h"
#include "Reestr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* \brief �������� ������ � ������� ������ �������� ReestrRecord (������ ������� ����� Catalog.txt)
* \return ��������� ����� ��� ������ �������� CatalogRecord
*/
Reestr* create_Reestr()
	{
	return (Reestr*)calloc(1, sizeof(Reestr));
	}

/**
* \brief ������� "��������������" ������ ��������
* \param file ������� ����, �� ��������� �������� ����������� ������
* \param structure ���������, ����� ������� ����� ������������� ��������
* \return ������������������ ��������� ReestrRecord
*/
void init_Reestr(FILE* file, Reestr* structure)
	{
	char* Q = fread_string(file);
	structure->length = atoi(Q);
	free(Q);
	structure->reestr = (ReestrRecord**)calloc(structure->length, sizeof(ReestrRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		ReestrRecord* record = create_ReestrRecord();
		init_ReestrRecord(record, tmp);
		structure->reestr[i] = record;
		free(tmp);
		}
	}

/**
* \brief ������� ��������� ������ ReestrRecord
* \param structure ��������� Reestr, � ������� ����� ����������� ��������� ReestrRecord
* \param record ����������� ���������
* \return ���������� ��������� � ��������� Reestr
*/
void add_ReestrRecord(Reestr* structure, ReestrRecord* record)
	{
	structure->length++;
	structure->reestr = (ReestrRecord**)realloc(structure->reestr, structure->length * sizeof(ReestrRecord*));
	structure->reestr[structure->length - 1] = record;
	}

/**
* \brief ������� ����������� ������ Reestr
* \param structure ���������, ������ ������� ����� �������������
* \return ������������� ������ ������� �������� Reestr
*/
void delete_Reestr(Reestr* structure)
	{
	for (int i = 0; i < structure->length; i++)
		delete_ReestrRecord(structure->reestr[i]);
	free(structure->reestr);
	free(structure);
	}