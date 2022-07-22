#include<iostream>
using namespace std;
int num[] = { 10,7,4,2,1,9,6,3,5,0};
int meet_value = 0;
int s_min = 0;
int s_max = 10;

void binary_search(int value,int left,int right)
{
	int mid = (right + left)/2;
	if( right < left){ return;}
	cout<<num[left]<<","<<num[mid]<<","<<num[right]<<" ";
	if(num[mid]==value)
	{
		meet_value = 1;
		return;
	}
	if( right == left)
	{
		return;
	}
	if(num[mid]<value)
	{
		binary_search(value,mid+1,right);
	}
	else if( num[mid]<value)
	{
		binary_search(value,left,mid-1);
	}
}
	void bs(int value)
	{
		meet_value = 0;
	}

