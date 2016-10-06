#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	
	int len;
	char * temp, str;
	if (argc == 2){
		len = strtol(argv[1], &temp, 10);
	} else {
		printf("You must enter the length of the binary string.\n");
		exit(0);
	}


	printf("%d\n", len);

	binString(str, len);

	return 0;
}

void binString(string str, int lenLeft){

	if (lenLeft == 0){
		printf("%s\n", str);
	} else {
		binString(strcat("0",str), lenLeft - 1);
		binString(strcat("1",str), lenLeft - 1);
	}
}

