#include "CatalogRecord.h"
#include "Functions.h"
#include "Catalog.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* \brief �������� ������ � ������� ������ �������� CatalogRecord (������ ������� ����� Catalog.txt)
* \return ��������� ����� ��� ������ �������� CatalogRecord
*/
Catalog* create_Catalog()
	{
	return (Catalog*)calloc(1, sizeof(Catalog));
	}

/**
* \brief ������� "��������������" ������ ��������
* \param file ������� ����, �� ��������� �������� ����������� ������
* \param structure ���������, ����� ������� ����� ������������� ��������
* \return ������������������ ��������� CatalogRecord
*/
void init_Catalog(FILE* file, Catalog* structure)
	{
	char* koefs = fread_string(file);
	structure->K_fot = atoi(strtok(koefs, " "));
	structure->K_nach = atoi(strtok(koefs, " "));
	structure->K_sfu = atoi(strtok(koefs, ""));
	free(koefs);
	char* N = fread_string(file);
	structure->length = atoi(N);
	free(N);
	structure->catalog = (CatalogRecord**)calloc(structure->length, sizeof(CatalogRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		CatalogRecord* record = create_CatalogRecord();
		init_CatalogRecord(record, tmp);
		structure->catalog[i] = record;
		free(tmp);
		}
	}

/**
* \brief ������� ��������� ������ CatalogRecord
* \param structure ��������� Catalog, � ������� ����� ����������� ��������� CatalogRecord
* \param record ����������� ���������
* \return ���������� ��������� � ��������� Catalog
*/
void add_CatalogRecord(Catalog* structure, CatalogRecord* record)
	{
	structure->length++;
	structure->catalog = (CatalogRecord**)realloc(structure->catalog, structure->length * sizeof(CatalogRecord*));
	structure->catalog[structure->length - 1] = record;
	}

/**
* \brief ������� ����������
* \param structure ��������� Catalog, � ������� ����� ����������� ��������� CatalogRecord
* \param record ����������� ���������
* \return ���������� ��������� � ��������� Catalog
*/
CatalogRecord* get_CatalogRecord_by_shortname(char* shortname, Catalog* catalog)
	{
	for (int i = 0; i < catalog->length; i++)
		{
		if (!strcmp(get_CatalogRecord_shortname(catalog->catalog[i]), shortname))
			{
			return catalog->catalog[i];
			}
		}
	return NULL;
	}

/**
* \brief ������� ����������� ������ Catalog
* \param structure ���������, ������ ������� ����� �������������
* \return ������������� ������ ������� �������� Catalog
*/
void delete_Catalog(Catalog* structure)
	{
	for (int i = 0; i < structure->length; i++)
		delete_CatalogRecord(structure->catalog[i]);
	free(structure->catalog);
	free(structure);
	}