#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, idx;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], rt[n], ct[n], wt[n], tat[n];

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while(completed < n) {
        idx = -1;
        int highest = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(pr[i] < highest) {
                    highest = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            rt[idx]--;
            time++;

            if(rt[idx] == 0) {
                completed++;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        }
        else {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}
