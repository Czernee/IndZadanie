#include "CatalogRecord.h"
#include "Functions.h"
#include "Catalog.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Catalog* create_Catalog()
	{
	return (Catalog*)calloc(1, sizeof(Catalog));
	}

void init_Catalog(FILE* file, Catalog* structure)
	{
	char* koefs = fread_string(file);
	structure->K_fot = atoi(strtok(koefs, " "));
	structure->K_nach = atoi(strtok(koefs, " "));
	structure->K_sfu = atoi(strtok(koefs, ""));
	free(koefs);
	char* N = fread_string(file);
	structure->length = atoi(N);
	structure->catalog = (CatalogRecord**)calloc(structure->length, sizeof(CatalogRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		CatalogRecord* record = create_CatalogRecord();
		init_CatalogRecord(record, tmp);
		structure->catalog[i] = record;
		}
	}

void add_CatalogRecord(Catalog* structure, CatalogRecord* record)
	{
	structure->length++;
	structure->catalog = (CatalogRecord**)realloc(structure->catalog, structure->length * sizeof(CatalogRecord*));
	structure->catalog[structure->length - 1] = record;
	}

void delete_Catalog(Catalog* structure)
	{
	free(structure->catalog);
	}