#include <stdio.h>

/** Here I assume that all processes come with sorted arrival time */

/**
 * input:
 * AT | BT
 * 1    5
 * 1    2
 * 1    3
 * quantum 2
 *
 * output:
The 1 process is executing
The 2 process is executing
The 3 process is executing
The 1 process is executing
The 3 process is executing
The 1 process is executing
 */
int ATT = 0;
int AWT = 0;
int CT;
int number_of_finished_precesses = 0;


//             | TAT | WT | AT  | BT | Remaining Time
// 1-process   |     |    |     |    |
//  ...        |     |    |     |    |
// n-th process|     |    |     |    |

/** Scheduling starts at time moment t=1*/


int main() {
    int n = 3; //number of processors
    int arr[n][5]; // Number of column is metrics - Turnaround time | Waiting time | Arrival time | Burst time | Remaining time
    // Here I have an array whose row is process number and columns are metrics
    int brr[n][5];
    int quantum;
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d:  ", i + 1);
        scanf("%d", &arr[i][2]);
        printf("Enter the burst time of process %d:  ", i + 1);
        scanf("%d", &arr[i][3]);
        arr[i][4] = arr[i][3];
        CT += arr[i][3];
    }
    printf("Enter quantum ");
    scanf("%d", &quantum);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            brr[i][j] = arr[i][j];
        }
    }
    while (number_of_finished_precesses != n) {
        for (int i = 0; i < n; i++) {
            if (brr[i][4] != 0) {
                printf("The %d process is executing \n", i + 1);
                if (brr[i][4] <= quantum) {
                    brr[i][4] = 0;
                    number_of_finished_precesses++;
                } else {
                    brr[i][4] -= quantum;
                }
            }
        }
    }
    printf("            TAT | WT | AT  | BT\n");
    for (int i = 0; i < n; i++) {
        printf("process %d ", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("\t%d ", brr[i][j]);
        }
        printf("\n");
    }
    printf("CT: %d\n", CT);

    return 0;
}