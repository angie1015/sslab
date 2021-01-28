#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"\nEnter number of philosophers  :";
	cin >> n;
	bool fork[n], phil_finished_eating[n], flag= true;
	for(int i = 0; i<n; i++)
			phil_finished_eating[i] = false;
	while(flag){
		cout<<"\nNew loop";
		for(int i = 0; i<n; i++)
			fork[i] = true; //clear forks
		flag = false;
		for(int i=0; i<n; i++){
		if(!phil_finished_eating[i]){
			if(fork[i] && fork[(i+1)%n]){
				fork[i] = false; // pick up left fork
				fork[(i+1)%n] = false; //pick up right fork
				cout<<"\nPhilosopher "<<i<<" is eating";
				phil_finished_eating[i] = true;
				flag = true;
			}else
				cout<<"\nPhilosopher "<<i<<" is thinking";
		}
		else
			cout<<"\nPhilosopher "<<i<<" has finished eating";
		}
		int i;
		for(i=0; i<n; i++){
			if(!phil_finished_eating[i])
				break;
		}
		if(i == n){
			cout<<"\nProgram completed successfully";
			exit(0);
		}
	}
	cout<<"\nDeadlock is present";
	return 0;
}
