#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
 int main(){
 	char string[128];
 	while(1){
        printf("> ");
        scanf("%s", string);
        system(string);
    }
    return 0;
 }