#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char flip();
int longestStreakFromStart(int size, char*allOutcomes);

int main(int argc, char * argv[]){

    //take in the number of flips
    int numFilps, i, seed, startStreakAv, longestStreakAv;
    char * temp;


    if (argc != 3){
        printf("You must enter the number of flips you wish to simulate and a seed.\n");
        exit(0);
    }
    numFilps = strtol(argv[1], &temp, 10);
    seed = strtol(argv[2], &temp, 10);            //

    

    for(i=0;i<10;i++){
        printf("%d\n", seed);
        char allOutcomes[numFilps];
        int j = 0;
        for (j=0;i<numFilps;i++){
            char out = flip(seed+i);
            printf("%c ", out);
            allOutcomes[i] = out;
        }
        int length = longestStreakFromStart(numFilps, allOutcomes);
        printf("%d\n", length);

        startStreakAv = startStreakAv + length;
        seed++;
    }
    return 0;
}

char flip(int seed){
    char outcome;
    srand(seed);

    double ranNum = (rand()%100);
    //printf("%f\n",ranNum);
    ranNum = ranNum/100;
    //printf("%f\n",ranNum);


    if (ranNum < 0.5)
        outcome = 'T';
    else 
        outcome = 'H';
    return outcome;
}

int longestStreakFromStart(int size, char*allOutcomes){
    int length, i;
    char firstOutcome = allOutcomes[0];
    length = 1;

    for (i=1;i<size;i++){
        if (allOutcomes[i] == firstOutcome)
            length++;
        else 
            break;
    }

    return length;
}