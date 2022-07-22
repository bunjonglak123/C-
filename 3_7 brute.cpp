#include<bits/stdc++.h>
using namespace std;

int ans[5] = {0,0,0,0,0};
int size = 5;
void brute (int j)
{
	if (j == size) 
	{
		for(int i=0;i<size;i++)
		{
		cout<<ans[i]<<" ";
		}
	cout<<endl;
	}
	else
	{
		int num = j+1;
		ans[j] = 0;
		brute(num);
		ans[j] = 1;
		brute(num);
	}
}
int main(){
	brute(0);
	return 0;
}

