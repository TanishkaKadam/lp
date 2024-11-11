#include<iostream>

using namespace std;



int main(){

    int n;

    cout<<"enter";

    cin>>n;



    float wtavg,tatavg;



    int bt[n],wt[n],tat[n];



    for(int i=0;i<n;i++){

        cout<<"Enter the burst time for the processes"<<i<<":";

        cin>>bt[i];

    }



    wt[0]=wtavg=0;

    tat[0]=tatavg=bt[0];



    for(int i=1;i<n;i++){

        wt[i]=wt[i-1]+bt[i-1];

        tat[i]=tat[i-1]+bt[i];

        wtavg+=wt[i];

        tatavg+=tat[i];

    }



    cout<<"/\nProcess \tBursttime  \tWaiting time  \t Turnaround time";



    for(int i=0;i<n;i++){

          cout<<"\nP"<<i<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];



    }

    cout<<"\n\nThe average waiting time "<<wtavg<<":"<<endl;

    cout<<"The average turnaround time "<<tatavg<<":"<<endl<<endl;









}

