#include <stdio.h>
int main() {
    int nop, p[10], bt[10], tat[10], wt[10];
    float avgtat = 0.0, avgwt = 0.0;
    printf("Enter the no. of processes: ");
    scanf("%d", &nop);
    printf("Enter Burst time of each process: ");
    for (int i = 0; i < nop; i++) {
        scanf("%d", &bt[i]);
        p[i] = i + 1;
        if (i == 0)
            tat[i] = bt[i];
        else
            tat[i] = tat[i - 1] + bt[i];
        wt[i] = tat[i] - bt[i];
        avgtat += tat[i];
        avgwt += wt[i];
    }
    avgtat = (float)(avgtat / nop);
    avgwt = (float)(avgwt / nop);
    printf("Process\tBT\tTAT\tWT\n");
    for (int i = 0; i < nop; i++)
        printf("%d\t%d\t%d\t%d\n", p[i], bt[i], tat[i], wt[i]);
    printf("\nAvg TAT: %f", avgtat);
    printf("\nAvg WT: %f\n", avgwt);
}
