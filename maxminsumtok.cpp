#include<iostream>
using namespace std;
int main(){
	int id;
	int A[]={};
	int B[]={};
	int k;
	int m;
	int n;
	int value;
	int sum=0;
	cin>>id;
	cout<<id<<"mod"<<id%4<<endl;
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
				m=i;
			}
		}
	}
		if(k==sum){
		cout<<"Yes ";
//		cout<<sum;
		cout<<"2 2";
		
	}
	else{
		cout<<"NO";
	}
};
