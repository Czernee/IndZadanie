#include <stdio.h>
#include <stdlib.h>

/*void Read_Catalog(const char* file_name);

typedef struct Catalog {
	char name[21];
	int hours;
	int akHours;
	char fullName[210];
} Catalog;


void Read_Catalog(const char* file_name) {
	FILE* file = fopen(file_name, "r");

	if (!file)
		exit(-1);

	int K_fot, K_nach, K_sfu, N; //Данные для Каталога

	fscanf(file, "%d %d %d %d", &K_fot, &K_nach, &K_sfu, &N);
	
	Catalog* sCatalog = NULL;	
	sCatalog = (Catalog*)malloc(N * sizeof(Catalog));

	for (int i = 0; i < N; i++)
		fscanf(file, "%s %d %d %[^\n]s", sCatalog[i].name, &sCatalog[i].hours, &sCatalog[i].akHours, sCatalog[i].fullName);

	free(sCatalog);

}
*/