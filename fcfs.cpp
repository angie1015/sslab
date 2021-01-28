#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main(){
   int n, i=0;
   cout<<"Enter number of processes  :";
   cin>>n;
   if(n==0)
       return 0;
   int bt[n], wt[n], tt[n];
   while(i<n){
      cout<<"\nEnter burst time of process "<<i<<" : ";
      cin>>bt[i];
      i++;
   }
   /* Turn Around Time: Time Difference between completion time and arrival time. 

           Turn Around Time = Completion Time – Arrival Time

      Waiting Time(W.T): Time Difference between turn around time and burst time.  */
   wt[0]= 0;
   tt[0]= bt[0];
   for(i=1; i<n; i++){
        wt[i] = bt[i-1] + wt[i-1];
        tt[i] = bt[i] + wt[i];
   }
   cout<<"\nProcess "<<" Burst Time "<< " Waiting time "<<" Turnaround Time\n";
   for(i=0; i<n; i++){
      cout<<i<<"      "<<bt[i]<<"            "<<wt[i]<<"              "<<tt[i]<<"\n";
   }
   return 0;
}
