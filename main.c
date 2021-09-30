#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

int main(int argsc, char** argsv) {
	
char letters[] = "abcdefghijklmnopqrstuvwxyz";
int count[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	FILE* in_file = fopen(argsv[1], "r"); // read only  
  
  if (! in_file )  {  
    printf("\noops, file can't be read\n"); 
    exit(-1); 
  }




	fseek(in_file, 0, SEEK_END); // seek to end of file
	int size = ftell(in_file); // get current file pointer
	fseek(in_file, 0, SEEK_SET);
	
	char n;
	for (n = getc(in_file); n != EOF; n = getc(in_file)){
		int i;

		for (i = 0; letters[i] != '\0';i++){

				if (n==letters[i]||n==letters[i]-32){
					count[i]++;
				}
			}
			
	}

	for  (int i = 0;letters[i] != '\0';i++){
				if (count[i]>0){
					printf("\nThe letter %c appears %d times",letters[i],count[i]);
				}

			}

  return 0;
}

