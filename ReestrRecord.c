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
	structure->RealizationBeginning = (char*)calloc(0, sizeof(char));
	structure->RealizationEnding = (char*)calloc(0, sizeof(char));
	char** info = separate_ReestrRecord_string(str);
	set_ReestrRecord_shortname(structure, info[0]);
	set_ReestrRecord_realizationbeginning(structure, info[1]);
	set_ReestrRecord_realizationending(structure, info[2]);
	set_ReestrRecord_price(structure, atoi(info[3]));
	set_ReestrRecord_studentsamount(structure, atoi(info[4]));
	set_ReestrRecord_groupsamount(structure, atoi(info[5]));
	for (int i = 0; i < 6; i++)
		free(info[i]);
	free(info);
	}

char* get_ReestrRecord_shortname(ReestrRecord* structure)
	{
	return structure->ShortName;
	}

char* get_ReestrRecord_realizationbeginning(ReestrRecord* structure)
	{
	return structure->RealizationBeginning;
	}

char* get_ReestrRecord_realizationending(ReestrRecord* structure)
	{
	return structure->RealizationEnding;
	}

int get_ReestrRecord_price(ReestrRecord* structure)
	{
	return structure->Price;
	}

int get_ReestrRecord_studentsamount(ReestrRecord* structure)
	{
	return structure->StudentsAmount;
	}

int get_ReestrRecord_groupsamount(ReestrRecord* structure)
	{
	return structure->GroupsAmount;
	}

void set_ReestrRecord_shortname(ReestrRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

void set_ReestrRecord_realizationbeginning(ReestrRecord* structure, char* RealizationBeginning)
	{
	structure->RealizationBeginning = (char*)realloc(structure->RealizationBeginning, (strlen(RealizationBeginning) + 1) * sizeof(char));
	strcpy(structure->RealizationBeginning, RealizationBeginning);
	}

void set_ReestrRecord_realizationending(ReestrRecord* structure, char* RealizationEnding)
	{
	structure->RealizationEnding = (char*)realloc(structure->RealizationEnding, (strlen(RealizationEnding) + 1) * sizeof(char));
	strcpy(structure->RealizationEnding, RealizationEnding);;
	}

void set_ReestrRecord_price(ReestrRecord* structure, int Price)
	{
	structure->Price = Price;
	}

void set_ReestrRecord_studentsamount(ReestrRecord* structure, int StudentsAmount)
	{
	structure->StudentsAmount = StudentsAmount;
	}

void set_ReestrRecord_groupsamount(ReestrRecord* structure, int GroupsAmount)
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
