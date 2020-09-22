#include <stdio.h>
#include <limits.h>

int clock = 0;
int ATT = 0;
int AWT = 0;

/** function for finding row-index of smallest element of array, k is number of rows */
int min_index(int arr[][4], int k) {
    int min_number, index = 0;
    min_number = arr[0][2];
    for (int i = 1; i < k; i++) {
        if (arr[i][2] < min_number) {
            min_number = arr[i][2];
            index = i;
        }
    }
    return index;
}

//             | TAT | WT | AT  | BT
// 1-process   |     |    |     |
//  ...        |     |    |     |
// n-th process|     |    |     |

int main() {
    int n = 3; //number of processors
    int arr[n][4]; // Number of column is metrics - Turnaround time | Waiting time | Arrival time | Burst time
    // Here I have an array whose row is process number and columns are metrics
    int brr[n][4];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d:  ", i + 1);
        scanf("%d", &arr[i][2]);
        printf("Enter the burst time of process %d:  ", i + 1);
        scanf("%d", &arr[i][3]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            brr[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int minIndex = min_index(arr, n);
        if (minIndex == 0) {
            brr[0][0] = brr[0][3];
            brr[0][1] = 0;
            AWT += brr[0][1];
            ATT += brr[0][0];
            clock += brr[0][3];
        } else {
            brr[minIndex][1] = clock - brr[minIndex][2];//waiting
            AWT += brr[minIndex][1];
            brr[minIndex][0] = brr[minIndex][1] + brr[minIndex][3];//TAT
            ATT += brr[minIndex][0];
            clock += brr[minIndex][3];
        }
        printf("The %d process is executing \n", minIndex + 1);
        arr[minIndex][2] = INT_MAX;
    }
    printf(" TAT | WT | AT  | BT\n ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            printf("\t%d ", brr[i][j]);
        }
        printf("\n");
    }
    printf("CT is %d\n", clock);
    printf("ATT is %f\n", (float) ATT / n);
    printf("AWR is %f", (float) AWT / n);

    return 0;
}

