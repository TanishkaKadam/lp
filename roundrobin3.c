/*Experiment No.: 3

Problem Statement : Write a program to simulate CPU Scheduling Algorithms: 
1.FCFS, 
2.SJF(Preemptive), 
3.Priority (Non-Preemptive) and 
4.Round Robin (Preemptive).*/




//3.Robin  :


#include<stdio.h>
int main() {
int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max; 
float awt = 0, att = 0, temp = 0;
printf("Enter the number of processes: "); 
scanf("%d",&n);
for(i = 0; i < n; i++) { 
printf("Enter Burst Time for Process %d: ", i + 1); 
scanf("%d", &bu[i]);
ct[i] = bu[i]; // Copy burst time to ct array for later calculations
}
printf("Enter the size of time slice: "); 
scanf("%d",&t);
max = bu[0]; 
for(i =1; i < n; i++) {
if(max < bu[i])
max = bu[i];
}
for(j = 0; j < (max / t) + 1; j++)
{ 
for(i = 0; i < n; i++) {
if(bu[i] != 0) { if(bu[i] <= t) {
tat[i] = temp + bu[i]; 
temp =temp + bu[i]; 
bu[i] = 0;
} 
else { 
bu[i] =bu[i] - t; 
temp =temp + t;
}
}
}
}
for(i = 0; i < n; i++) {
wa[i] = tat[i] - ct[i];
att += tat[i]; 
awt +=wa[i];
}
printf("\nAverage Turnaround Time: %.2f", att / n); 
printf("\nAverage Waiting Time: %.2f\n", awt / n);
printf("\nPROCESS\t BURST TIME \t WAITING TIME\t TURNAROUND TIME\n"); 
for(i= 0; i < n; i++) {
printf("%d\t %d\t\t %d\t\t %d\n", i + 1, ct[i], wa[i], tat[i]);
}
return 0;
}
