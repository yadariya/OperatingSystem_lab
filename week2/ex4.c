#include <stdio.h>

void replace(int *n1, int *n2) { //function for swapping to variables
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int main() {
    int number1;
    int number2;
    scanf_s("%d%d", &number1, &number2);
    printf("Before: %d %d\n", number1, number2);
    replace(&number1, &number2);
    printf("After: %d %d", number1, number2);
}
