#include<iostream>
using namespace std;

int Fibonacci(int num) //TREE
{
	if(num == 0)		{return 0;}
	else if(num == 1)	{return 1;}
	else			 	{return(Fibonacci(num-1)+Fibonacci(num-2));}
}

int main(){
	cout<<Fibonacci(4)<<endl;
	return 0;
}

