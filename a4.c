
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

	int vertices;
	char c;
	FILE * fp;
	fp = fopen(fileName, "r"); //open file

	if (fp == NULL){
		printf("file not found\n");
		exit(0);
	}

	c = fgetc(fp);
	printf("%c\n", c);

	while(c != EOF){
		vertices = (int)c - '0';
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
printf("%s\n", row);
char a = getch();
			char *token = strtok(row," ");
			while(token != NULL){
				if (strcmp(token,"1") == 0)
					g1[i]++;
			}
		}
		//print the results of the first graph
		printf("Degree Sequence for G1: ");
		for (i=0;i<vertices;i++){
			printf(" %d",g1[i]);
		}
		printf("\n");
		//get the next character
		c = fgetc(fp) - '0';
		vertices = (int)c;

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
		c = fgetc(fp);

	}
	
	return 0;
}

