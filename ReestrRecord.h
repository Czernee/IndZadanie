#ifndef REESTRECORD_H
#define REESTRRECORD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ReestrRecord
	{
	char* ShortName;
	double RealizationBeginning;
	double RealizationEnding;
	int Price;
	int StudentsAmount;
	int GroupsAmount;
	} ReestrRecord;

ReestrRecord* create_ReestrRecord();
void init_ReestrRecord(ReestrRecord* structure, char* str);
char* get_ReestrRecord_shortname(ReestrRecord* structure);
float get_ReestrRecord_realizationbeginning(ReestrRecord* structure);
float get_ReestrRecord_realizationending(ReestrRecord* structure);
int get_ReestrRecord_price(ReestrRecord* structure);
int get_ReestrRecord_studentsamount(ReestrRecord* structure);
int get_ReestrRecord_groupsamount(ReestrRecord* structure);
void set_ReestrRecord_shortname(ReestrRecord* structure, char* ShortName);
void set_ReestrRecord_realizationbeginning(ReestrRecord* structure, double RealizationBeginning);
void set_ReestrRecord_realizationending(ReestrRecord* structure, double RealizationEnding);
void set_ReestrRecord_price(ReestrRecord* structure, int Price);
void set_ReestrRecord_studentsamount(ReestrRecord* structure, int StudentsAmount);
void set_ReestrRecord_groupsamount(ReestrRecord* structure, int GroupsAmount);
char** separate_ReestrRecord_string(char* str);
void delete_ReestrRecord(ReestrRecord* structure);

#endif