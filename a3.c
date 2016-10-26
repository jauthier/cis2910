#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char flip();

int main(int argc, char * argv[]){

    //take in the number of flips
    int numFilps, i;
    char * temp;

    if (argc == 1){
        printf("You must enter the number of flips you wish to simulate.\n");
        exit(0);
    }
    numFilps = strtol(argv[1], &temp, 10);

    for (i=0;i<numFilps;i++){
        char out = flip();
        printf("%c\n", out);
    }


    return 0;
}

char flip(){
    char outcome;
    double ranNum = (rand()%100)/100;
    if (ranNum < 0.5)
        outcome = 'T';
    else 
        outcome = 'H';
    return outcome;
}