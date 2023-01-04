#include "CatalogRecord.h"
#include "Functions.h"
#include "CatalogRecord.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CatalogRecord* create_CatalogRecord()
	{
	return (CatalogRecord*)calloc(1, sizeof(CatalogRecord));
	}

void init_CatalogRecord(CatalogRecord* structure, char* str)
	{
	structure->ShortName = (char*)calloc(0, sizeof(char));
	structure->FullName = (char*)calloc(0, sizeof(char));
	char** info = separate_CatalogRecord_string(str);
	set_CatalogRecord_shortname(structure, info[0]);
	set_CatalogRecord_hours(structure, atoi(info[1]));
	set_CatalogRecord_akademhours(structure, atoi(info[2]));
	set_CatalogRecord_fullname(structure, info[3]);
	for (int i = 0; i < 4; i++)
		free(info[i]);
	free(info);
	}

char* get_CatalogRecord_shortname(CatalogRecord* structure)
	{
	return structure->ShortName;
	}

int get_CatalogRecord_hours(CatalogRecord* structure)
	{
	return structure->Hours;
	}

int get_CatalogRecord_akademhours(CatalogRecord* structure)
	{
	return structure->AkademHours;
	}

char* get_CatalogRecord_fullname(CatalogRecord* structure)
	{
	return structure->FullName;
	}

void set_CatalogRecord_shortname(CatalogRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

void set_CatalogRecord_hours(CatalogRecord* structure, int Hours)
	{
	structure->Hours = Hours;
	}

void set_CatalogRecord_akademhours(CatalogRecord* structure, int AkademHours)
	{
	structure->AkademHours = AkademHours;
	}

void set_CatalogRecord_fullname(CatalogRecord* structure, char* FullName)
	{
	structure->FullName = (char*)realloc(structure->FullName, (strlen(FullName) + 1) * sizeof(char));
	strcpy(structure->FullName, FullName);
	}

char** separate_CatalogRecord_string(char* str)
	{
	char** info = (char**)calloc(4, sizeof(char*));
	char* ShortName = strtok(str, " ");
	char* Hours = strtok(NULL, " ");
	char* AkademHours = strtok(NULL, " ");
	char* FullName = strtok(NULL, "");
	strcpy(info[0], ShortName);
	strcpy(info[1], Hours);
	strcpy(info[2], AkademHours);
	strcpy(info[3], FullName);
	return info;
	}

void delete_CatalogRecord(CatalogRecord* structure)
	{
	free(structure->ShortName);
	free(structure->FullName);
	free(structure);
	}
