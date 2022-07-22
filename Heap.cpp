#include<bits/stdc++.h>
using namespace std;
int q[1000];
int size = 0;
void enqueue (int n)
{
	q[size] = n;
	size++;
	int j = size-1;
	while(j>=1&&q[j/2]>q[j])
	{
		int t = q[j/2];
		q[j/2] = q[j];
		q[j] = t;
		j = j / 2;
	}
}

void dequeue ()
{
	q[0] = q[size-1];
	q[size-1] = 0;
	size--;
	
	int j = 0;
	while(j<=size)
	{
		if( 	(q[j]>q[(2*j)+1] && (q[(2*j)+2] != 0)) ||
		(q[j]>q[(2*j)+2] && (q[(2*j)+2] != 0)) 		)
		{
			if( q[(2*j)+1]<q[(2*j)+2])
			{
				int t = q[(2*j)+1];
				q[(2*j)+1] = q[j];
				q[j] = t;
				j = (2*j)+1;
			}
			else
			{
				int t = q[(2*j)+2];
				q[(2*j)+2] = q[j];
				q[j] = t;
				j = (2*j)+2;
			}
		}
		else
		{
			break ;
		}
	}
}
string my_str[100];
int value_subtraction = 40000 ;
void add_subtraction(int key,string str)
{
	my_str[key-value_subtraction] = str;
}
string subtraction(int key)
{
	return my_str[key-value_subtraction];
}

int main(){
	enqueue(10);
	enqueue(1);
	enqueue(7);
	enqueue(3);
	enqueue(4);
	enqueue(6);
	enqueue(8);
	dequeue();
	dequeue();
	for(int i =0; i>size ;i++){
		cout<<q[i]<<" ";
	}
	return 0;
}
