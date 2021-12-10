#define _CRT_SECURE_NO_WARNINGS
#define DEBUG 0
#define UNIT 0101
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#pragma warning(disable : 4996)

int main()
{
	system("cls");
	char current;
	int k = 1;
	int pos, i, j, n, l=0, length, dem = 0;
	int min = 99999999;
	FILE* file;
	int full;
	scanf_s("%d", &n);					
	int** a = (int**)malloc((n + 1) * sizeof(int*));		
	int* e = (int*)calloc(n, sizeof(int));
	for (int arr = 0; arr < n; arr++)			
	{
		a[arr] = (int*)malloc(sizeof(int));
	}
	current = getchar();			
	for (i = 0; i < n; i++)
	{
		printf("%d  : ", i + 1);
		current = getchar();			
		for (j = 0; current != '\n'; j++)	
		{
			if ((current == '1') || (current == '0'))
			{
				a[i] = (int*)realloc(a[i], sizeof(int) * k);	
				(a[i])[k - 1] = (int)current - '0';		
				++k;						
			}
			current = getchar();	
		}
		current = '\0';
		length = k - 1;				
		k = 1;					
	}
	printf("\n\n");
	// сравнение данных (поиск минимума) //
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < length; j++) {
			dem = dem + a[i][j];
		} 
		if (dem < min) {
			min = dem;
		}
		e[i] = dem;
		dem = 0;
		if (i == n - 1) {
			for (int l = 0; l < n; l++) {
				if ((e[l]) == min) {
					printf("%2d", l+1);
				}
			}
		}
	}
	
	
	
	if ((file = fopen("Dot_file.txt", "w+b")) == NULL) {	
		printf("Cannot open file.\n");			
		exit(1);					
	}
	fprintf(file, "graph G{\n");				


	int t = -1;				
	full = 0;				
	for (i = 0; i < n; i++)
	{
		fprintf(file, "\t%d;\n", (i + 1));
	}
	for (j = 0; j < length; j++)			
	{
		for (i = 0; i < n; i++)				
		{
			if ((a[i][j] == 1) && (full > 2))  
			{
				
				exit(-1);
			}
			else {
				if ((a[i][j] == 1) && (full == 0)) {       
					fprintf(file, "\t%d", (i + 1));	 
					fprintf(file, " -- ");
					full++;				 
					t = i;				 
				}
				else {

					if ((a[i][j] == 1) && (full == 1)) {      

						fprintf(file, "%d", (i + 1));	
						fprintf(file, " [label=%c];\n", (j + UNIT));
						full++;
					}
				}
			}
		}
		if (t != -1) {
			if (full == 1) {			
				fprintf(file, "\t%d", (t + 1));   
				fprintf(file, ";\n");
			}
		}
		full = 0;		
		t = -1;
	}
	fprintf(file, "}");
	fclose(file);		
	system("dot -Tbmp Dot_file.txt -o Dot_file.bmp");	
	
	free(a);
	getchar();
	return 0;
}