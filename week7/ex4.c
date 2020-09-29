#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *reallocByDariya(void *ptr, size_t size) {
    if (size == 0) { //If size is equal to zero, the call is equivalent to free(ptr)
        free(ptr);
        return NULL;
    }
    if (ptr == NULL) {  // If ptr is NULL, the call is equivalent to malloc(size)
        ptr = malloc(size);
        return ptr;
    }
    if (size <= sizeof(ptr)) {
        return ptr;
    } else {
        void *ptr1 = malloc(size);// new pointer
        memcpy(ptr1, ptr, size);
        free(ptr);
        return ptr1;
    }

}

int main() {
    printf("Enter original array size:");
    int n1 = 0;
    scanf("%d", &n1);

    //Create a new array of n1 ints
    int *a1 = malloc(n1 * sizeof(int));
    int i;
    for (i = 0; i < n1; i++) {
        //Set each value in a1 to 100
        *(a1 + i) = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", *(a1 + i));
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Dynamically change the array to size n2
    a1 = reallocByDariya(a1, sizeof(int) * n2);

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
    if (n2 > n1) {
        for (int i = 0; i < n2; i++) {
            *(a1 + i) = 0;
        }
    }

    for (i = 0; i < n2; i++) {
        //Print each element out (to make sure things look right)
        printf("%d ", *(a1 + i));
    }
    printf("\n");
}
