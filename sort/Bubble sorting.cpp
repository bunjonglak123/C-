#include<iostream>
using namespace std;

int main(){

int n[] = {1,2,3,4,5,6,7,8,9};
int size = 9;
for(int i = 0 ; i < (size-1) ; i++)
{
	for(int j=0;j<(size-i)-1;j++)
	{
		if(n[j]>n[j+1])
		{
			int t =n[j+1];
			n[j+1]=n[j];
			n[j]=t;
		}
	}
}
for(int i=0;i<size;i++)
{
	cout<<n[i]<<" ";
}
return 0;
}
