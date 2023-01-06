#include "ReestrRecord.h"
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ReestrRecord* create_ReestrRecord()
	{
	return (ReestrRecord*)calloc(1, sizeof(ReestrRecord));
	}

void init_ReestrRecord(ReestrRecord* structure, char* str)
	{
	structure->ShortName = (char*)calloc(0, sizeof(char));
	structure->RealizationBeginningMonth = (char*)calloc(0, sizeof(char));
	structure->RealizationBeginningYear = (char*)calloc(0, sizeof(char));
	structure->RealizationEndingMonth = (char*)calloc(0, sizeof(char));
	structure->RealizationEndingYear = (char*)calloc(0, sizeof(char));
	char** info = separate_ReestrRecord_string(str);
	set_ReestrRecord_shortname(structure, info[0]);
	char** date = separate_date(info[1]);
	set_ReestrRecord_realization_beginning_month(structure, date[0]);
	set_ReestrRecord_realization_beginning_year(structure, date[1]);
	char** date1 = separate_date(info[2]);
	set_ReestrRecord_realization_ending_month(structure, date1[0]);
	set_ReestrRecord_realization_ending_year(structure, date1[1]);
	set_ReestrRecord_price(structure, atoi(info[3]));
	set_ReestrRecord_students_amount(structure, atoi(info[4]));
	set_ReestrRecord_groups_amount(structure, atoi(info[5]));
	for (int i = 0; i < 6; i++)
		free(info[i]);
	free(info);
	for (int i = 0; i < 2; i++)
		free(date[i]);
	for (int i = 0; i < 2; i++)
		free(date1[i]);
	free(date);
	free(date1);
	}

char* get_ReestrRecord_shortname(ReestrRecord* structure)
	{
	return structure->ShortName;
	}

char* get_ReestrRecord_realization_beginning_month(ReestrRecord* structure)
	{
	return structure->RealizationBeginningMonth;
	}

char* get_ReestrRecord_realization_beginning_year(ReestrRecord* structure)
	{
	return structure->RealizationBeginningYear;
	}

char* get_ReestrRecord_realization_ending_month(ReestrRecord* structure)
	{
	return structure->RealizationEndingMonth;
	}

char* get_ReestrRecord_realization_ending_year(ReestrRecord* structure)
	{
	return structure->RealizationEndingYear;
	}

int get_ReestrRecord_price(ReestrRecord* structure)
	{
	return structure->Price;
	}

int get_ReestrRecord_students_amount(ReestrRecord* structure)
	{
	return structure->StudentsAmount;
	}

int get_ReestrRecord_groups_amount(ReestrRecord* structure)
	{
	return structure->GroupsAmount;
	}

void set_ReestrRecord_shortname(ReestrRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

void set_ReestrRecord_realization_beginning_month(ReestrRecord* structure, char* RealizationBeginning)
	{
	structure->RealizationBeginningMonth = (char*)realloc(structure->RealizationBeginningMonth, (strlen(RealizationBeginning) + 1) * sizeof(char));
	strcpy(structure->RealizationBeginningMonth, RealizationBeginning);
	}

void set_ReestrRecord_realization_beginning_year(ReestrRecord* structure, char* RealizationBeginning)
	{
	structure->RealizationBeginningYear = (char*)realloc(structure->RealizationBeginningYear, (strlen(RealizationBeginning) + 1) * sizeof(char));
	strcpy(structure->RealizationBeginningYear, RealizationBeginning);
	}

void set_ReestrRecord_realization_ending_month(ReestrRecord* structure, char* RealizationEnding)
	{
	structure->RealizationEndingMonth = (char*)realloc(structure->RealizationEndingMonth, (strlen(RealizationEnding) + 1) * sizeof(char));
	strcpy(structure->RealizationEndingMonth, RealizationEnding);
	}

void set_ReestrRecord_realization_ending_year(ReestrRecord* structure, char* RealizationEnding)
	{
	structure->RealizationEndingYear = (char*)realloc(structure->RealizationEndingYear, (strlen(RealizationEnding) + 1) * sizeof(char));
	strcpy(structure->RealizationEndingYear, RealizationEnding);
	}


void set_ReestrRecord_price(ReestrRecord* structure, int Price)
	{
	structure->Price = Price;
	}

void set_ReestrRecord_students_amount(ReestrRecord* structure, int StudentsAmount)
	{
	structure->StudentsAmount = StudentsAmount;
	}

void set_ReestrRecord_groups_amount(ReestrRecord* structure, int GroupsAmount)
	{
	structure->GroupsAmount = GroupsAmount;
	}

char** separate_ReestrRecord_string(char* str)
	{
	char** info = (char**)calloc(6, sizeof(char*));
	char* ShortName = strtok(str, " ");
	info[0] = (char*)calloc(strlen(ShortName) + 1, sizeof(char));
	char* RealizationBeginning = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(RealizationBeginning) + 1, sizeof(char));
	char* RealizationEnding = strtok(NULL, " ");
	info[2] = (char*)calloc(strlen(RealizationEnding) + 1, sizeof(char));
	char* Price = strtok(NULL, " ");
	info[3] = (char*)calloc(strlen(Price) + 1, sizeof(char));
	char* StudentsAmount = strtok(NULL, " ");
	info[4] = (char*)calloc(strlen(StudentsAmount) + 1, sizeof(char));
	char* GroupsAmount = strtok(NULL, "");
	info[5] = (char*)calloc(strlen(GroupsAmount) + 1, sizeof(char));
	strcpy(info[0], ShortName);
	strcpy(info[1], RealizationBeginning);
	strcpy(info[2], RealizationEnding);
	strcpy(info[3], Price);
	strcpy(info[4], StudentsAmount);
	strcpy(info[5], GroupsAmount);
	return info;
	}

void delete_ReestrRecord(ReestrRecord* structure)
	{
	free(structure->ShortName);
	free(structure);
	}
