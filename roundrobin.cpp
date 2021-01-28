#include<iostream>
using namespace std;

int main(){
  int n;
  cout<< "Enter number of processes :\n";
  cin >> n;
  cout<< "Enter burst times :\n";
  int bt[n], rem_bt[n], wt[n], t = 0, tat[n], qtm;
  for(int i = 0; i<n; i++){
     cin >> bt[i];
     rem_bt[i] = bt[i];
  }
  cout<< "Enter time quantum :\n";
  cin>> qtm;
  while(1){
     bool done = true;
     for(int i = 0; i<n; i++){
        if(rem_bt[i] > qtm){
           done = false;
           t += qtm;
           rem_bt[i] -= qtm;
        }else if(rem_bt[i] != 0){
           t += rem_bt[i];
           rem_bt[i] = 0;
           wt[i] = t-bt[i];
           tat[i] = bt[i] + wt[i];
           cout<<bt[i]<<" "<<wt[i]<<" "<<tat[i]<<"\n";
         }
      }
      if(done == true)
         break;
  }
  cout<<"Processes   Burst Time   Waiting Time    Turnaround Time\n";
  for(int i = 0; i<n; i++){
      cout<<i+1<<"       "<<bt[i]<<"            "<<wt[i]<<"             "<<tat[i]<<"\n";
       
  }
return 0;
}
