#ifndef CATALOG_H
#define CATALOG_H

#include "CatalogRecord.h"
#include <stdlib.h>
#include <stdio.h>

/**
* \struct Catalog
* \brief ��������� ��� �������� ������� �������� CatalogRecord (������ ������� ����� Catalog.txt)
* \param K_fot ����������� ����� ������ �����
* \param R_nach ����������� ����� ���������� �� ������ �����
* \param K_sfu ����������� ����� �������� ���
* \param catalog ������ �������� CatalogRecord
* \param length ������ ������� �������� Catalog
*/

typedef struct Catalog
	{
	int K_fot;
	int K_nach;
	int K_sfu;
	CatalogRecord** catalog;
	size_t length;
	} Catalog;

Catalog* create_Catalog();
void init_Catalog(FILE* file, Catalog* structure);
void add_CatalogRecord(Catalog* structure, CatalogRecord*);
CatalogRecord* get_CatalogRecord_by_shortname(char*, Catalog*);
void delete_Catalog(Catalog* structure);

#endif