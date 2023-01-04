#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "CatalogRecord.h"

int main()  
    {

    FILE* finCatalog = fopen("Catalog.txt", "r");
    check_file(finCatalog);

    char* str = fread_string(finCatalog);

    CatalogRecord* bebra = create_CatalogRecord();
    init_CatalogRecord(bebra, str);
    printf("%s %d %d %s", bebra->ShortName, bebra->Hours, bebra->AkademHours, bebra->FullName);
    delete_CatalogRecord(bebra);

    fclose(finCatalog);

	return 0;
    }

