#include <stdio.h>

void make(int n) {
    for (int i = 0; i < n; i += 1) {
        int k = 0;
        for (int m = 0; m < n - i; m += 1) {
            printf(" "); // i is row number, m is used to calculate how much ' ' we need to print
        }
        while (k != 2 * i + 1) { // k is used to calculate how much '*' we need to print
            printf("*");
            k += 1;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf_s("%d", &n);
    make(n);
}

