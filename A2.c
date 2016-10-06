#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;

void binString(char * str, int lenLeft, char ** list);
int twoToThe(int num);

int main(int argc, char* argv[]){

	int len;
	char *temp;
	char str1[3], str2[3];
	if (argc == 2){
		len = strtol(argv[1], &temp, 10);
	} else {
		printf("You must enter the length of the binary string.\n");
		exit(0);
	}

	char * list[twoToThe(len)];
	count = 0;

	strcpy(str1,"0");
	binString(str1, len-1, list);

	strcpy(str2, "1");
	binString(str2, len-1, list);

	

	return 0;
}

void binString(char * str, int lenLeft, char ** list){

	if (lenLeft == 0){
		list[count];
		count ++;
		printf("%s\n", str);
	} else {
		char temp1[10], temp2[10];
		strcpy(temp1, str);
		strcat(temp1, "0");
		binString(temp1, lenLeft - 1, list);

		strcpy(temp2, str);
		strcat(temp2, "1");
		binString(temp2, lenLeft - 1, list);
	}
}

int twoToThe(int num){
	int sum = 1;
	int i = 0;
	for(i=0; i<num; i++){
		sum = sum * 2;
	}
	return sum;
}


