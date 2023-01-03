#include <stdio.h>
#include "ReadFileCatalog.h"

int main()
    {
    FILE* fout = fopen("output.txt", "w");
    // Нужно посчитать 𝑉𝑖 = 𝑇𝑖 ∙ 𝑁𝑖
	if (!fout)
		exit(1);

    Read_Catalog("Catalog.exe");
    
	return 0;
    fclose(fout);
    }

