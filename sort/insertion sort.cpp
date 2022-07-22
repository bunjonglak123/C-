#include<bits/stdc++.h>
using namespace std;

int main(){

int n[] = {1,2,3,4,5,6,7,8,9};
int size = 9;
int temp1= 0;
for(int i=1;i<size;i++){
for(int j=(i-1);j>=0;j--){
			if( n[j]>n[j+1])
			{
				temp1=n[i];
				n[j]=n[j+1];
				n[j+1] = temp1;
			}
			else{
				break;
			}
		}
	}
for(int i=0;i<size;i++)
{
	cout<<n[i]<<" ";
}
return 0;
}
