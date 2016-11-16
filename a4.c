
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

	char *fileName;
	if (argc == 2)
		fileName = argv[0];
	else
		fileName = "input-graphs.txt";

	int vertices;
	char c, *temp;
	//holds the degree of each verticy
	int g1[vertices], g2[vertices];

	//open file
	FILE * fp = fopen(fileName, "r");
	c = fgetc(fp);
	
	while(c != EOF){
		
		//graph 1
		vertices = (int)c;
		int i = 0;
		for (i=0;i<vertices;i++){
			
			char row[vertices*2];
			fgets(row,vertices*2,fp);

			char *token = strtok(row," ");
			while(token != NULL){
				if (strcmp(token,"1") == 0)
					g1[i]++;
			}
		}
		//print the results of the first graph
		prinf("Degree Sequence for G1: ");
		for (i=0;i<vertices;i++){
			prinf(" %d",g1[i]);
		}
		//get the next character
		c = fgetc(fp);
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
		prinf("Degree Sequence for G2: ");
		for (i=0;i<vertices;i++){
			prinf(" %d",g2[i]);
		}
		//get the next character
		c = fgetc(fp);

	}
	
	return 0;
}

