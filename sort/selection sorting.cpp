#include<iostream>
using namespace std;

int main(){

int n[] = {1,2,3,4,5,6,7,8,9};
int size = 9;
for(int i = 0 ; i < size ; i++)
{
	int t = i;
	for(int j=i;j<size;j++)
	{
		if(n[t]>n[j])
		{
			t=j;
		}
	}
	int tt =n[i];
	n[i]=n[t];
	n[t]=tt;
}
for(int i=0;i<size;i++)
{
	cout<<n[i]<<" ";
}
return 0;
}
