#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readLine(char * line);

int main(int argc, char * argv[]){

    char *fileName;

    if (argc == 2)
        fileName = argv[1];
    else 
        fileName = "ass5-graphs.txt";

    int vertices, i;
    char v[6];
    char *temp;
    FILE * fp = fopen(fileName, "r"); //open file

    if (fp == NULL){ //check file pointer is not NULL
        printf("file not found\n");
        exit(0);
    }
    while(fgets(v, 6, fp) != NULL){ //get the number of verticies
        printf("v: %s\n",v);
        vertices = strtol(v, &temp, 10); // convert the string to an int
        int degreeCount[vertices]; // define an array to hold the degree count for each vetex
        i = 0;
        for (i=0;i<vertices;i++){ // initalize the array
            degreeCount[i] = 0;
        }
        i = 0;
        for (i=0;i<vertices;i++){ // go through the graph line by line
            char line[(vertices*2)+1];
            
            fgets(line, (vertices*2)+1, fp);
            printf("%s",line);
            degreeCount[i] = readLine(line);
            printf("degree: %d\n",degreeCount[i])
        }
    }

    return 0;
}

int readLine(char * line){
    int count = 0;
    char * token;
    token = strtok(line, " \n");
    while(token != NULL){
        if (strcmp(token,"1") == 0){
            count++;
        }
        token = strtok(NULL," \n");
    }

    return count;
}
