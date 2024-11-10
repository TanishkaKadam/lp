//sjf preemptive code




#include <iostream>
#include <climits>
using namespace std;

int main() {
    int bt[20], wt[20], tat[20], ct[20], at[20], remaining_bt[20], n, i, j, t = 0;
    float wtavg = 0, tatavg = 0;
    
    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter Arrival Time for Process " << i+1 << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for Process " << i+1 << ": ";
        cin >> bt[i];
        remaining_bt[i] = bt[i];  // Initialize remaining burst time
    }

    int completed = 0, min_bt, shortest, finish_time;
    bool check[n] = {0}; // To check if the process is completed

    while (completed < n) {
        min_bt = INT_MAX;
        shortest = -1;

        // Find process with minimum burst time that has arrived and not completed
        for (i = 0; i < n; i++) {
            if (at[i] <= t && !check[i] && remaining_bt[i] < min_bt && remaining_bt[i] > 0) {
                min_bt = remaining_bt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            t++; // If no process is ready to execute, increment time
            continue;
        }

        // Execute the selected process for one time unit
        remaining_bt[shortest]--;
        t++;

        // If the process is completed
        if (remaining_bt[shortest] == 0) {
            check[shortest] = 1;
            completed++;
            finish_time = t;
            ct[shortest] = finish_time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            wtavg += wt[shortest];
            tatavg += tat[shortest];
        }
    }

    cout << "\nPROCESS \tARRIVAL TIME \tBURST TIME \tCOMPLETION TIME \tTURNAROUND TIME \tWAITING TIME\n";
    for (i = 0; i < n; i++) {
        cout << "\n\t P" << i << "\t\t " << at[i] << "\t\t " << bt[i] << "\t\t " << ct[i] << "\t\t " << tat[i] << "\t\t " << wt[i];
    }

    cout << "\nAverage Waiting Time -- " << wtavg / n;
    cout << "\nAverage Turnaround Time -- " << tatavg / n;

    return 0;
}


/* to run this code
ubuntu@Tanishka:~$ cd Desktop
ubuntu@Tanishka:~/Desktop$ g++ sjf_preemptive.cpp
ubuntu@Tanishka:~/Desktop$ ./a.out
*/
