#include<bits/stdc++.h>
using namespace std;

int J[4][4] = { {9,2,7,8}, {6,4,3,7}, {5,8,1,8}, {7,6,9,4} } ;
int size = 4;
int Arr[100];
void permute(int j)
{
	if(j == size)
	{
		int sum =0;
		for(int i=0;i<size;i++){
			sum=sum+J[Arr[i]-1][Arr[i+1]-1];
		}
		
		for(int i=0;i<size;i++){
			cout<<Arr[i]-1<<" ";
		}
		cout<<sum<<endl;
	}
	else
	{
		for(int i=j; i<size;i++)
		{
			int T = Arr[j];
			Arr[j] = Arr[i];
			Arr[i] = T;
			permute(j+1);
			T = Arr[j];
			Arr[j] = Arr[i];
			Arr[i] = T;
		}
	}
}

int main(){
	for(int i=0;i<100;i++){Arr[i] = i+1;}
	permute(0);
	return 0;
}


