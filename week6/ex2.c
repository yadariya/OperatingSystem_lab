#include <stdio.h>
#include <limits.h>

/** Here I assume that all processes come with sorted arrival time */

int clock = 0;
int ATT = 0;
int AWT = 0;

/** function for finding row-index of smallest element of array, k is number of rows */
int min_index(int arr[][4], int k) {
    int min_number, index = 0;
    min_number = arr[0][3];
    for (int i = 1; i < k; i++) {
        if (arr[i][3] < min_number) {
            min_number = arr[i][3];
            index = i;
        }
    }
    return index;
}

//             | TAT | WT | AT  | BT
// 1-process   |     |    |     |
//  ...        |     |    |     |
// n-th process|     |    |     |

/** Scheduling starts at time moment t=1*/

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
        if (i == 0) {
            brr[minIndex][0] = brr[minIndex][3];
            brr[minIndex][1] = 0;
            AWT += brr[minIndex][1];// average waiting time
            ATT += brr[minIndex][0];// average turnaround time
            clock += brr[minIndex][3];
        } else {
            if (clock - brr[minIndex][2] < 0) { brr[minIndex][1] = 0; }
            else { brr[minIndex][1] = clock - brr[minIndex][2] + 1; }//waiting
            AWT += brr[minIndex][1];
            brr[minIndex][0] = brr[minIndex][1] + brr[minIndex][3];//TAT
            ATT += brr[minIndex][0];
            clock += brr[minIndex][3];
        }
        printf("The %d process is executing \n", minIndex + 1);
        arr[minIndex][3] = INT_MAX;
    }
    printf("            TAT | WT | AT  | BT\n");
    for (int i = 0; i < n; i++) {
        printf("process %d ", i + 1);
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