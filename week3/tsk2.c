#include <stdio.h>

#define MAX_SIZE 10

void replace(int *n1, int *n2) { //function for swapping to variables
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}


void bubble_sort(int arr[]) {
    for (int i = 0; i < MAX_SIZE - 1; i += 1) {
        for (int j = 0; j < MAX_SIZE - i - 1; j += 1) {
            if (arr[j] > arr[j + 1]) {
                replace(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i += 1) {
        scanf_s("%d", &arr[i]);
    }
    bubble_sort(arr);
    for (int i = 0; i < MAX_SIZE; i += 1) {
        printf("%d ", arr[i]);
    }
    return 0;
}
