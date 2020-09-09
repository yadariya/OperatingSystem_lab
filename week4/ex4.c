#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
 int main(){
 	char *string=NULL;
 	size_t n=0;
 	while(1){
        printf("> ");
        ssize_t len = getline(&string, &n, stdin);
        string[len - 1] = '\0';
        if (strcmp(string,"exit")==0){
        	break;
        }
        system(string);
        free(string);
        n = 0;
        string = NULL;
    }
    return 0;
 }
