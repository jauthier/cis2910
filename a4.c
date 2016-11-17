
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

	char *fileName;

	if (argc == 2)
		fileName = argv[1];
	else 
		fileName = "input-graphs.txt";

	int vertices, i;
	char c[500];
	char *temp;
	FILE * fp = fopen(fileName, "r"); //open file

	if (fp == NULL){
		printf("file not found\n");
		exit(0);
	}

	while(fgets(c, 5, fp) != NULL){
		vertices = strtol(c, &temp, 10);
		int g1[vertices];
		int g2[vertices];

		//initialize arrays
		i = 0;
		for (i=0;i<vertices;i++){
			g1[i] = 0;
			g2[i] = 0;
		}

		//graph 1
		i = 0;
		for (i=0;i<vertices;i++){
			char row[vertices*2];
			fgets(row,40,fp);
			char *token = strtok(row," \n");
			while(token != NULL){
				if (strcmp(token,"1") == 0){
					g1[i]++;
				}
				token = strtok(NULL," \n");
			}
		}

		//print the results of the first graph
		printf("Degree Sequence for G1: ");
		for (i=0;i<vertices;i++){
			printf(" %d",g1[i]);
		}
		printf("\n");
		
		//get the next character
		fgets(c, 2, fp);
		fgets(c, 2, fp);
		vertices = strtol(c, &temp, 10);
		fgets(c, 2, fp);
		//graph 2
		
		i = 0;
		for (i=0;i<vertices;i++){
			char row[vertices*2];
			fgets(row,40,fp);
			char *token = strtok(row," \n");
			while(token != NULL){
				if (strcmp(token,"1") == 0){
					g2[i]++;
				}
				token = strtok(NULL," \n");
			}
		}
			

		//print the results of the second graph
		i = 0;
		printf("here\n");
		printf("Degree Sequence for G2: ");
		for (i=0;i<vertices;i++){
			printf(" %d",g2[i]);
		}

		i = 0;
		int check = 0;
		while (i < vertices && check != 1){
			if (g1[i] != g2[i])
				check = 1;
		}
		if (check == 1)
			printf("The graphs DO have the same degree sequence.\n");
		else
			printf("The graphs DO NOT have the same degree sequence.\n");

		fgets(c, 2, fp);
	}
	
	return 0;
}
