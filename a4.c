
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){


	char *fileName;
	if (argc == 2){
		fileName = argv[1];
	}
	else {
		fileName = "input-graphs.txt";
	}
printf("here1\n");
	int vertices;
	char c[500];
	char *temp;
	FILE * fp;
	fp = fopen(fileName, "r"); //open file
printf("here2\n");
	if (fp == NULL){
		printf("file not found\n");
		exit(0);
	}
printf("here3\n");
	fgets(c, 5, fp); //get the initial number
printf("%s",c);
	while(c != NULL){
		vertices = strtol(c, &temp, 10);
		printf("%d\n", vertices);
		int g1[vertices];
		int g2[vertices];

		//graph 1
		int i = 0;
		for (i=0;i<vertices;i++){
			printf("in first graph\n");
			char row[vertices*2];
			printf("here\n");
			fgets(row,40,fp);
			if (strcmp(row, "\n") == 0)
				printf("null\n");
			printf("%s\n", row);
			char *token = strtok(row," ");
			printf("%s\n",token);
			while(token != NULL){
				if (strcmp(token,"1") == 0)
					g1[i]++;
				token = strtok(NULL," ");
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
		vertices = strtol(c, &temp, 10);

		//graph 2
		i = 0;
		for (i=0;i<vertices;i++){
			
			char row[vertices*2];
			fgets(row,vertices*2,fp);

			char *token = strtok(row," ");
			while(token != NULL){
				if (strcmp(token,"1") == 0)
					g1[i]++;
			}
		}

		//print the results of the second graph
		printf("\nDegree Sequence for G2: ");
		for (i=0;i<vertices;i++){
			printf(" %d",g2[i]);
		}
		//get the next character
		fgets(c, 2, fp);

	}
	
	return 0;
}

