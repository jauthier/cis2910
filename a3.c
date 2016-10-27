#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char flip();
int longestStreakFromStart(int size, char*allOutcomes);

int main(int argc, char * argv[]){

    //take in the number of flips
    int numFilps, i, seed;
    double startStreakAv, longestStreakAv;
    char * temp;


    if (argc != 3){
        printf("You must enter the number of flips you wish to simulate and a seed.\n");
        exit(0);
    }
    numFilps = strtol(argv[1], &temp, 10);
    seed = strtol(argv[2], &temp, 10);            

    for(i=0;i<10;i++){
        printf("%d\n", seed);
        char allOutcomes[numFilps];
        int j = 0;
        for (j=0;j<numFilps;j++){
            char out = flip(seed+j);
            printf("%c ", out);
            allOutcomes[j] = out;
        }
        int length = longestStreakFromStart(numFilps, allOutcomes);
        printf("%d\n", length);
        int longest = longestStreak(numFilps, allOutcomes);

        startStreakAv = startStreakAv + length;
        seed++;
    }
    startStreakAv = startStreakAv/10;
    printf("Longest starting streak average: %f\n", startStreakAv);
    return 0;
}

char flip(int seed){
    char outcome;
    srand(seed);

    double ranNum = (rand()%100);
    ranNum = ranNum/100;

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

int longestStreak(int size, char*allOutcomes){
    int longest, hold, i;
    char compare = allOutcomes[0];
    hold = 1;
    longest = 1;
    for (i=1;i<size;i++){
        printf("char:%c, compare: %c, i: %d, hold: %d, longest: %d\n",allOutcomes[i], compare,i,hold, longest);
        if (allOutcomes[i] == compare){
            hold ++;
            if (hold > longest)
                longest = hold;
        } else {
            compare = allOutcomes[i];
            if (hold > longest)
                longest = hold;
            hold = 1;
        }
    }
printf("%d\n", longest);
    return longest;
}