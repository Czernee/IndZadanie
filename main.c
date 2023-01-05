#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "CatalogRecord.h"
#include "ReestrRecord.h"
#include "TableRecord.h"

int main()  
    {

    FILE* finCatalog = fopen("Catalog.txt", "r");
    FILE* finReestr = fopen("Reestr.txt", "r");
    check_file(finCatalog);
    check_file(finReestr);

    char* str = fread_string(finCatalog);
    char* str1 = fread_string(finReestr);

    CatalogRecord* bebra = create_CatalogRecord();
    init_CatalogRecord(bebra, str);
    printf("%s %d %d %s\n", bebra->ShortName, bebra->Hours, bebra->AkademHours, bebra->FullName);
    delete_CatalogRecord(bebra);

    ReestrRecord* bebra1 = create_ReestrRecord();
    init_ReestrRecord(bebra1, str1);
    printf("%s %f %f %d %d %d\n", bebra1->ShortName, bebra1->RealizationBeginning, bebra1->RealizationEnding, bebra1->Price, bebra1->StudentsAmount, bebra1->GroupsAmount);
    delete_ReestrRecord(bebra1);

    fclose(finCatalog);
    fclose(finReestr);

	return 0;
    }

