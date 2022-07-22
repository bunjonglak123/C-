#include<iostream>
using namespace std;
int main(){
	int id;
	int A[]={};
	int B[]={};
	int k=0;
	int m=0;
	int n=0;
	int value;
	int sum=0;
//	cin>>id;
	cin>>n;
	cin>>k;
	for(int i=0; i<n;i++)
	{
		cin>>value;
		A[i]={value};
	}
	for(int i=0; i<n;i++)
	{
		B[i]=A[i];
	}
	for(int i=0; i<n;i++)
	{
		if(k==sum)
		{
			break;
		}
		else{
			for(int i=0; i<n;i++){
				sum=A[i]+B[i+1];
			}
		}
	}
		if(k==sum){
		cout<<"Yes";
	}
	else{
		cout<<"NO";
	}
//	cout<<id<<"mod"<<id%4<<endl;
};
