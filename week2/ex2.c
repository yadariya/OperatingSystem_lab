#include <stdio.h>
#include <string.h>


int main() {
    char string[255];
    printf("Enter the string");
    printf("\n");
    scanf("%s", string);
    for (int i = strlen(string) - 1; i >= 0; i -= 1) { // I use strlen(string) - 1 no to print  null '\0' character
        putchar(string[i]);
    }
}
