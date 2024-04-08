#include <stdio.h>

int main() {
    int A[100][5]; // Added an extra column for arrival time
    int n, total = 0, index, temp;
    float avg_tat, avg_wt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and arrival time: ");
    for(int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &A[i][1], &A[i][4]); // Storing burst time and arrival time
        A[i][0] = i + 1;
    }
    
    for(int i = 0; i < n; i++) {
        index = i;
        for(int j = i; j < n; j++) {
            if(A[j][4] < A[index][4]) { // Sorting based on arrival time
                index = j;
            }
            temp = A[i][1];
            A[i][1] = A[index][1];
            A[index][1] = temp;

            temp = A[i][0];
            A[i][0] = A[index][0];
            A[index][0] = temp;

            temp = A[i][4]; // Also swap arrival times
            A[i][4] = A[index][4];
            A[index][4] = temp;
        }
    }
    A[0][2] = 0;

    for(int i = 1; i < n; i++) {
        A[i][2] = 0;
        for(int j = 0; j < i; j++) {
            A[i][2] += A[j][1];
        }
        total += A[i][2];
    }

    avg_wt = (float)total / n;
    total = 0;
    printf("P     BT     WT     TAT\n");

    for(int i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];
        printf("P%d     %d     %d      %d\n", A[i][0], A[i][1], A[i][2], A[i][3]);   
    }
    avg_tat = (float)total / n;
    printf("Average Waiting time= %f", avg_wt);
    printf("\nAverage Turn Around time= %f", avg_tat);
    return 0;
}
