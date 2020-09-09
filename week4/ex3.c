#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
 int main(){
 	char string[128];
 	while(1){
        printf("> ");
        scanf("%s", string);
        if (strcmp(string,"exit")==0){
        	break;
        }
        system(string);
    }
    return 0;
 }