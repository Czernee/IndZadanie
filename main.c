#include <stdio.h>
#include "Functions.h"


int main()
    {
    FILE* finCatalog = fopen("Catalog.txt", "r");

	if (!finCatalog)
		exit(1);

    char* str = fread_string(finCatalog);
    char* str1 = fread_string(finCatalog);

    printf("%s\n%s\n", str, str1);
    
    fclose(finCatalog);
	return 0;
    }

