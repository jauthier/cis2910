#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readLine(char * line);
int numEdges(int * g, int vertices);
int largestDegree(int * g, int vertices);
int checkEulerian(int * g, int vertices);

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

        vertices = strtol(v, &temp, 10); // convert the string to an int
        printf("%s, %d\n",v, vertices);
        int degreeCount[vertices]; // define an array to hold the degree count for each vetex
        i = 0;
        for (i=0;i<vertices;i++){ // initalize the array
            degreeCount[i] = 0;
        }
        i = 0;
        for (i=0;i<vertices;i++){ // go through the graph line by line
            char line[(vertices*2)+1];
            fgets(line, (vertices*2)+1, fp);
            printf("line %d: %s\n", i, line);
            char b = getchar();
            degreeCount[i] = readLine(line);
        }

        // after all of the lines of the graph have been read
        int edges = numEdges(degreeCount,vertices);
        int largest = largestDegree(degreeCount,vertices);
        int eularian = checkEulerian(degreeCount,vertices);
        printf("Number of Edges: %d, largest degree: %d, eularian: %d\n",edges,largest,eularian);
        char c = getchar();
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

int numEdges(int * g, int vertices){
    int sum = 0;
    int i = 0;

    // count all the edges
    for (i=0;i<vertices;i++){
        sum = sum + g[i];
    }
    return sum/2;
}

int largestDegree(int * g, int vertices){
    int largest = 0;
    int i = 0;

    for (i=0;i<vertices;i++){
        if (g[i] > largest)
            largest = g[i];
    }
    return largest;
}

int checkEulerian(int * g, int vertices){
    // check if the graph is connected
    int i = 0;
    int checkC = 1;
    for (i=0;i<vertices;i++){
        if (g[i] == 0){
            checkC = 0;
            break;
        }
    }

    //check if all vertices have  even degree
    i = 0;
    int checkD = 1;
    for (i=0;i<vertices;i++){
        if (g[i]%2 != 0){ // if the degree is odd
            checkD = 0;
            break;
        }
    }
    if (checkD == 1 && checkC == 1)
        return 1;
    else
        return 0;
}