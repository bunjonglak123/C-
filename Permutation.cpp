#include<bits/stdc++.h>
using namespace std;
//TSP
int D[4][4] = { {9999,2,3,1}, {2,9999,4,5}, {3,4,9999,8}, {1,5,8,9999} };
int size = 5;
int Arr[100];
void permute(int j)
{
	if(j == size)
	{
		int sum_D = 0;
		for(int i=0; i <size-1 ; i++)
		{
			sum_D = sum_D + D[Arr[i]-1][Arr[i+1]-1];
		 } 
		for(int i=0 ; i<size;i++) 
		{
			cout<<Arr[i]-1<<" ";	
		} 
		cout<<sum_D<<endl;
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


