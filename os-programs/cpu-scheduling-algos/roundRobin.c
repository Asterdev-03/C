#include <stdio.h>
int main() {
    int nop, time = 0, p[10], quant, wt[10], tat[10], bt[10], rbt[10];
    float avgwt = 0.0, avgtat = 0.0;
    printf("Enter no. of processes: ");
    scanf("%d", &nop);
    int rnop = nop;
    printf("Enter the Time Quantum: ");
    scanf("%d", &quant);
    printf("Enter Burst Time of each process: ");
    for (int i = 0; i < nop; i++) {
        scanf("%d", &bt[i]);
        p[i] = i + 1;
        rbt[i] = bt[i];
    }
    for (int i = 0; rnop != 0; i = (i + 1) % nop)
        if (rbt[i] <= quant && rbt[i] > 0) {
            time += rbt[i];
            rbt[i] = 0;
            rnop--;
            tat[i] = time;
            wt[i] = tat[i] - bt[i];
            avgtat += tat[i];
            avgwt += wt[i];
        }
        else if (rbt[i] > 0) {
            rbt[i] -= quant;
            time += quant;
        }
    avgtat = (float)(avgtat / nop);
    avgwt = (float)(avgwt / nop);
    printf("Process\tBT\tTAT\tWT\n");
    for (int i = 0; i < nop; i++)
        printf("%d\t%d\t%d\t%d\n", p[i], bt[i], tat[i], wt[i]);
    printf("\nAvg TAT: %f", avgtat);
    printf("\nAvg WT: %f\n", avgwt);
}