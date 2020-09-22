#include <stdio.h>
#include <limits.h>

/** function for finding row-index of smallest element of array, k is number of rows */
int min_index(int arr[][7], int k) {
    int min_number, index = 0;
    min_number = arr[0][5];
    for (int i = 1; i < k; i++) {
        if (arr[i][5] < min_number) {
            min_number = arr[i][5];
            index = i;
        }
    }
    return index;
}

//             | CT | TAT | WT | ATT | AVT
// 1-process   |    |     |    |     |
//  ...        |    |     |    |     |
// n-th process|    |     |    |     |

int main() {
    int n = 5; //number of processors
    int arr[n][7]; // Number of column is 7 because of 5 metrics (CT,TAT,WT,ATT,AVT )+ 2 columns for arrival time and burst time
    // Here I have an array whose row is process number and columns are metrics
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Enter the %d parameter for %d process  ", j + 1, i + 1);
            scanf("%d", &arr[i][j]);
        }
        printf("Enter the arrival time of process %d:  ", i + 1);
        scanf("%d", &arr[i][5]);
        printf("Enter the burst time of process %d:  ", i + 1);
        scanf("%d", &arr[i][6]);
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 0; i < n; i++) {
        int minIndex = min_index(arr, n);
        printf("The %d process is executing \n", minIndex + 1);
        arr[minIndex][5] = INT_MAX;
    }
    return 0;
}

