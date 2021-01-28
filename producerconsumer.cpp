#include<iostream>
using namespace std;

int main(){
	int i = -1, n, c, data;
	cout<<"\nEnter size of buffer  :";
	cin>>n;
	int buffer[n];
	while(1){
		cout<<"\n1. Produce\t2. Consume\t3. Exit\nEnter your choice  :";
		cin>>c;
		switch(c){
			case 1: if(i<n-1){
					cout<<"\nEnter data to produce  :";
					cin >> data;
					buffer[++i] = data;
				}else
					cout<<"\nSemaphore is full!";
				break;
			case 2: if(i>=0){
					cout<<"\nData consumed is "<<buffer[i--];
				}else
					cout<<"\nSemaphore is empty!";
				break;
			default: exit(0);
		}
	}
	return 0;
}
