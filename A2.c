#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	
	int len;
	char * temp;
	if (argc == 2){
		len = strtol(argv[1], &temp, 10);
	} else {
		printf("You must enter the length of the binary string.\n");
		exit(0);
	}

	printf("%d\n", len);


	return 0;
}


