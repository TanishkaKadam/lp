/*Experiment No.: 3

Problem Statement : Write a program to simulate CPU Scheduling Algorithms: 
1.FCFS, 
2.SJF(Preemptive), 
3.Priority (Non-Preemptive) and 
4.Round Robin (Preemptive).*/




//2.SJF  :

#include<stdio.h>
int main() {
int p[20], bt[20], wt[20], tat[20], n, i, j, temp; 
float wtavg = 0, tatavg = 0;
printf("\nEnter the number of processes: "); 
scanf("%d",&n);
printf("\nEnter Burst Time for each process:\n");
for(i = 0; i < n; i++) { p[i] = i + 1; 
// Process numbers from 1 to n printf("P%d: ", p[i]);
scanf("%d", &bt[i]);
}
for(i = 0; i < n - 1; i++) { 
for(j= 0; j < n - i - 1; j++) {
if(bt[j] > bt[j + 1]) {
temp = bt[j]; 
bt[j]= bt[j + 1]; 
bt[j +1] = temp; temp= p[j]; 
p[j] = p[j+ 1]; p[j + 1] =temp;
}
}
}
wt[0] = 0; for(i = 1; i <n; i++) { 
wt[i] = 0; 
for(j= 0; j < i; j++) {
wt[i] += bt[j];
}
}
for(i = 0; i < n; i++) {
tat[i] = bt[i] + wt[i];
}
for(i = 0; i < n; i++) {
wtavg += wt[i];
tatavg += tat[i]; 
}
wtavg /= n; 
tatavg /=n;
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
for(i = 0; i< n; i++) {
printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
}
printf("\nAverage Waiting Time: %.2f", wtavg); 
printf("\nAverage Turnaround Time: %.2f\n", tatavg);
return 0;
}



/* to run this program use 
gcc sjf2.c
./a.out */
