#include<bits/stdc++.h>
using namespace std;

int num[1000];

bool sequence_search(int value, int size){
	for(int i=0;i<size;i++){
		cout<<num[i]<<" ";
		if(num[i]==value){			
			return 1;
		}
	}
	return 0;
}

int main()
{
	int size=0;	
	string s ;
	do{		
		cin>>s;
    	stringstream str(s);
    		
    	if(s!="p"&&s!="s"){
			str >> num[size];  
    		size++;
		}else if(s=="p"){
			for(int loop=0;loop<size;loop++){
				cout<<num[loop] ;
				cout<<" ";
			}	
			cout<<endl;
		}else if(s=="s"){
			int search;
			cin>>search;
			bool check = sequence_search(search,size);
			if(check==1){
				cout<<"Yes"<<endl;
			}else if(check==0){
				cout<<"No"<<endl;
			}
		}
		if(s=="o"){
			exit( 3 );
		}		
	}while(true);
}
