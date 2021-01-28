#include<iostream>
using namespace std;

int main(){
	int n, m;
	cout<<"\nEnter no. of processes  :\n";
	cin>>n;
	cout<<"Enter no. of resources  :\n";
	cin>>m;
	int avail[m], alloc[n][m], max[n][m], f[n], ans[n], ind= 0, need[n][m];
	cout<<"Enter available resources  :\n";
	for(int i=0; i<m; i++)
             cin>>avail[i];
	cout<<"Enter maximum available resources for process :\n";
	for(int i=0; i<n; i++){
		cout<<i+1<<"  :\n";
		for(int j=0; j<m; j++)
			cin>>max[i][j];
		}
	cout<<"Enter allocated resources for process :\n";
	for(int i=0; i<n; i++){
		cout<<i+1<<"  :\n";
		for(int j=0; j<m; j++)
			cin>>alloc[i][j];
		}
	for(int i=0; i<n; i++)
		f[i] = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	for(int k = 0; k<10; k++){
		for(int i=0; i<n; i++){
			int flag=0;
			for(int j=0; j<m; j++){
				if(need[i][j] > avail[j]){
					flag=1; break;
				}
			}
			if(flag==0){
				ans[ind++] = i;
				for(int j=0; j<m; j++)
					avail[j] += alloc[i][j];
				f[i] = 1;
			}
		}
        }
	cout<<"Safe sequence:\n";
	for(int i=0; i<n-1; i++)
		cout<<"P"<<ans[i]+1<<" -> ";
	cout<<"P"<<ans[n-1]+1;

}
