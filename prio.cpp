#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cout<<"\nEnter no. of processes  :\n";
   cin>>n;
   cout<<"Enter burst times and priority:\n";
   int bt[n], tat[n], wt[n], pr[n], p[n];
   for(int i = 0; i<n; i++){
      p[i] = i+1;
      cin>>bt[i]>>pr[i];
   }
   for(int i = 0; i< n; i++){
      for(int j = i+1; j< n; j++){
        if(pr[i]>pr[j]){
           swap(p[i], p[j]);
           swap(bt[i], bt[j]);
           swap(pr[i], pr[j]);
        }
      }
   }
    wt[0] = 0;
    tat[0] = bt[0];
    for(int i = 1; i< n; i++){
      wt[i] = wt[i-1] + bt[i-1];
      tat[i] = bt[i]+wt[i];
    }
    cout<<"Process    "<<"Burst time   "<<"Waiting Time "<<"Turnaround time\n";
    for(int i = 0; i< n; i++){
       cout<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
   }
   return 0;
}
