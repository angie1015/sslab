#include<bits/stdc++.h>
using namespace std;

struct directory{
  string dname;
  vector<string> fname;
  int fcount;
}dir;
int main(){
   cout<<"\nEnter name of the directory  :\n";
   cin>>dir.dname;
   dir.fcount = 0;
   while(1){
       cout<<"1.Create new file\t2. Delete File\t3. Search for file\t4. Display file\t5. Exit\nEnter your choice  :\n";
       int ch;
       cin>>ch;
	string f;
	switch(ch){
		case 1: cout<<"Enter name of new file   :\n";
			cin >> f;
			if(dir.fname.size() == dir.fcount){
                               dir.fname.push_back(f);
                          }else{
				dir.fname[dir.fcount] = f;
			}
				dir.fcount++;
			break;
		case 2: cout<<"Enter name of file to delete  :\n";
			cin >> f;
			int i;
			for(i = 0; i<dir.fcount; i++){
				if(dir.fname[i] == f){
					dir.fname[i] = dir.fname[dir.fcount - 1];
				}
				dir.fcount--;
			}
			if(i==dir.fcount) cout<<"\nFile not found!\n";
			break;
		case 3: cout<<"Enter name of file to search  :\n";
			cin >> f;
			int k;
			for(k = 0; k<dir.fcount; k++){
				if(dir.fname[k] == f){
					cout<<"File found!\n"; break;
				}
			}
			if(k==dir.fcount) cout<<"\nFile not found!\n";
			break;
		case 4: 
			for(int j = 0; j<dir.fcount; j++){
					cout<<dir.fname[j]<<"\n"; 
			}
			break;	
		default: exit(0);

        }
  }
return 0;
}
