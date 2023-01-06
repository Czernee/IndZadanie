#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "CatalogRecord.h"
#include "ReestrRecord.h"
#include "TableRecord.h"
#include "Catalog.h"
#include "Reestr.h"
#include "Table.h"


int main()  
    {

    FILE* finCatalog = fopen("Catalog.txt", "r");
    FILE* finReestr = fopen("Reestr.txt", "r");
    FILE* finTable = fopen("tab_12_2022.txt", "r");

    check_file(finCatalog);
    check_file(finReestr);
    check_file(finTable);

    Catalog* catalog = create_Catalog();
    init_Catalog(finCatalog, catalog);
    printf("%s %d %d %s\n", catalog->catalog[0]->ShortName, catalog->catalog[0]->Hours, catalog->catalog[0]->AudHours, catalog->catalog[0]->FullName);
    printf("%s %d %d %s\n", catalog->catalog[1]->ShortName, catalog->catalog[1]->Hours, catalog->catalog[1]->AudHours, catalog->catalog[1]->FullName);
    printf("%s %d %d %s\n", catalog->catalog[2]->ShortName, catalog->catalog[2]->Hours, catalog->catalog[2]->AudHours, catalog->catalog[2]->FullName);
    printf("-------------------------------------------\n");

    Reestr* reestr = create_Reestr();
    init_Reestr(finReestr, reestr);
    printf("%s %s %s %s %s %d %d %d\n", reestr->reestr[0]->ShortName, reestr->reestr[0]->RealizationBeginningMonth, reestr->reestr[0]->RealizationBeginningYear, reestr->reestr[0]->RealizationEndingMonth, reestr->reestr[0]->RealizationEndingYear, reestr->reestr[0]->Price, reestr->reestr[0]->StudentsAmount, reestr->reestr[0]->GroupsAmount);
    printf("%s %s %s %s %s %d %d %d\n", reestr->reestr[1]->ShortName, reestr->reestr[1]->RealizationBeginningMonth, reestr->reestr[1]->RealizationBeginningYear, reestr->reestr[1]->RealizationEndingMonth, reestr->reestr[1]->RealizationEndingYear, reestr->reestr[1]->Price, reestr->reestr[1]->StudentsAmount, reestr->reestr[1]->GroupsAmount);
    printf("%s %s %s %s %s %d %d %d\n", reestr->reestr[2]->ShortName, reestr->reestr[2]->RealizationBeginningMonth, reestr->reestr[2]->RealizationBeginningYear, reestr->reestr[2]->RealizationEndingMonth, reestr->reestr[2]->RealizationEndingYear, reestr->reestr[2]->Price, reestr->reestr[2]->StudentsAmount, reestr->reestr[2]->GroupsAmount);
    printf("-------------------------------------------\n");

    Table* table = create_Table();
    init_Table(finTable, table);
    printf("%s %s %d\n", table->table[0]->FamilyIO, table->table[0]->ShortName, table->table[0]->AudHours);
    printf("%s %s %d\n", table->table[1]->FamilyIO, table->table[1]->ShortName, table->table[1]->AudHours);
    printf("%s %s %d\n", table->table[2]->FamilyIO, table->table[2]->ShortName, table->table[2]->AudHours);
    printf("%s %s %d\n", table->table[3]->FamilyIO, table->table[3]->ShortName, table->table[3]->AudHours);
    printf("%s %s %d\n", table->table[4]->FamilyIO, table->table[4]->ShortName, table->table[4]->AudHours);

    fclose(finCatalog);
    fclose(finReestr);
    fclose(finTable);

	return 0;
    }

