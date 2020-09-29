#include <stdio.h>
#include <stdlib.h>


int main() {
    int N;
    printf("Enter the integer number N: ");
    scanf("%d", &N);
    int *array = malloc(N * sizeof(int)); //dynamically allocate memory
    for (int i = 0; i < N; i++) {
        *(array + i) = i;
    }
    for (int i = 0; i < N; i++) {
        printf("    %d", *(array + i)); //print
    }
    free(array);//deallocate the memory
    return 0;
}
