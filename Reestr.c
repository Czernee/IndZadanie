#include "ReestrRecord.h"
#include "Functions.h"
#include "Reestr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//---------------------------------------------------------------------------------
// ������� ������� ������ �������� ReestrRecord (������ ������� ����� Reestr.txt)
Reestr* create_Reestr()
	{
	return (Reestr*)calloc(1, sizeof(Reestr));
	}

//---------------------------------------------------------------------------------
// ������� "��������������" ������ ��������
// ��. ������: ���� � ��������, ���������, �� ��������� ������� ����� ����������� ������
void init_Reestr(FILE* file, Reestr* structure)
	{
	char* Q = fread_string(file);
	structure->length = atoi(Q);
	structure->reestr = (ReestrRecord**)calloc(structure->length, sizeof(ReestrRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		ReestrRecord* record = create_ReestrRecord();
		init_ReestrRecord(record, tmp);
		structure->reestr[i] = record;
		}
	}

//---------------------------------------------------------------------------------
// ������� ��������� ������ ReestrRecord
// ��. ������: ���������, � ������� ����������� ������, ������
void add_ReestrRecord(Reestr* structure, ReestrRecord* record)
	{
	structure->length++;
	structure->reestr = (ReestrRecord**)realloc(structure->reestr, structure->length * sizeof(ReestrRecord*));
	structure->reestr[structure->length - 1] = record;
	}

//---------------------------------------------------------------------------------
// ������� ����������� ������ Reestr
// ��. ������: ���������
void delete_Reestr(Reestr* structure)
	{
	free(structure->reestr);
	}