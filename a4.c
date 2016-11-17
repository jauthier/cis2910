
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
			printf("row: %d\n", i);
			char row[vertices*2];
			fgets(row,40,fp);
			char *token = strtok(row," \n");
			while(token != NULL){
				printf("token: %s\n", token);
				if (strcmp(token,"1") == 0){
					g1[i]++;
					printf("added\n");
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

		//graph 2
		
		int j = 0;
		printf("graph 2: %d\n",vertices);
		for (j=0;j<vertices;j++){
			printf("here\n");
			char row[vertices*2];
			fgets(row,40,fp);
			char *token = strtok(row," \n");
			while(token != NULL){
				printf("token: %s\n", token);
				if (strcmp(token,"1") == 0){
					g2[j]++;
					printf("added\n");
				}
				token = strtok(NULL," \n");
			}
		}

		//print the results of the second graph
		i = 0;
		printf("Degree Sequence for G2: ");
		for (i=0;i<vertices;i++){
			printf(" %d",g2[i]);
		}
	}
	
	return 0;
}

