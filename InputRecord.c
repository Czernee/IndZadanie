#include "InputRecord.h"
#include "Functions.h"
#include <stdlib.h>
#include <string.h>

InputRecord* create_InputRecord()
	{
	return (InputRecord*)calloc(1, sizeof(InputRecord));
	}

void init_InputRecord(InputRecord* structure, char* str)
	{
	//выделение места для фамилии и иницалов преподавателей
	structure->Keyword = (char*)calloc(0, sizeof(char));
	structure->FamilyIO = (char*)calloc(0, sizeof(char));
	structure->Month = (char*)calloc(0, sizeof(char));
	structure->Year = (char*)calloc(0, sizeof(char));
	//info для всех полей InputRecord (записи строки input.txt)
	char** info = separate_InputRecord_string(str);
	char** date = separate_date(info[2]);
	set_InputRecord_keyword(structure, info[0]);
	set_InputRecord_familyio(structure, info[1]);
	set_InputRecord_month(structure, date[0]);
	set_InputRecord_year(structure, date[1]);
	for (int i = 0; i < 2; i++)
		free(date[i]);
	for (int i = 0; i < 3; i++)
		free(info[i]);
	free(info);
	free(date);
	}	

char* get_InputRecord_keyword(InputRecord* structure)
	{
	return structure->Keyword;
	}


char* get_InputRecord_familyio(InputRecord* structure)
	{
	return structure->FamilyIO;
	}

char* get_InputRecord_month(InputRecord* structure)
	{
	return structure->Month;
	}

char* get_InputRecord_year(InputRecord* structure)
	{
	return structure->Year;
	}

void set_InputRecord_keyword(InputRecord* structure, char* Keyword)
	{
	structure->Keyword = (char*)realloc(structure->Keyword, (strlen(Keyword) + 1) * sizeof(char));
	strcpy(structure->Keyword, Keyword);
	}

void set_InputRecord_familyio(InputRecord* structure, char* FamilyIO)
	{
	structure->FamilyIO = (char*)realloc(structure->FamilyIO, (strlen(FamilyIO) + 1) * sizeof(char));
	strcpy(structure->FamilyIO, FamilyIO);
	}

void set_InputRecord_month(InputRecord* structure, char* Month)
	{
	structure->Month = (char*)realloc(structure->Month, (strlen(Month) + 1) * sizeof(char));
	strcpy(structure->Month, Month);
	}

void set_InputRecord_year(InputRecord* structure, char* Year)
	{
	structure->Year = (char*)realloc(structure->Year, (strlen(Year) + 1) * sizeof(char));
	strcpy(structure->Year, Year);
	}

char** separate_InputRecord_string(char* str)
	{
	char** info = (char**)calloc(3, sizeof(char*));
	char* Keyword = strtok(str, " ");
	info[0] = (char*)calloc(strlen(Keyword) + 1, sizeof(char));
	char* FamilyIO = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(FamilyIO) + 1, sizeof(char));
	char* Date = strtok(NULL, "");
	info[2] = (char*)calloc(strlen(Date) + 1, sizeof(char));
	strcpy(info[0], Keyword);
	strcpy(info[1], FamilyIO);
	strcpy(info[2], Date);
	return info;
	}

void delete_InputRecord(InputRecord* structure)
	{
	free(structure->FamilyIO);
	free(structure->Month);
	free(structure->Year);
	free(structure);
	}