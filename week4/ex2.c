#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	for(int i=0;i<5;i+=1){
		fork();
	}
	sleep(5);
}
