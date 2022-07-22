#include<bits/stdc++.h>
using namespace std;

class Queue
{
public:
int a[10000];
int size = 0;

void Print(){
	for(int i = 0; i<size; i++)
	{
		cout << a[i]<<" ";
	}
	cout<<endl;
}

void Enqueue(int data)
{
	a[size] = data;
	size++;
}

int Dequeue()
{	
	if(size>0)
	{
		int s = a[0];
		for(int i=1; i < size ;i++)
		{
			a[i-1]=a[i];
		}
		size = size-1;
		return s;
	}
	return -1;
}

};
int main(){
	Queue s;
	s.Enqueue(1); s.Print();
	s.Enqueue(2); s.Print();
	s.Enqueue(3); s.Print();
	s.Enqueue(4); s.Print();
	s.Enqueue(5); s.Print();
	cout<<s.Dequeue()<<"\t"; s.Print();
	cout<<s.Dequeue()<<"\t"; s.Print();
	cout<<s.Dequeue()<<"\t"; s.Print();
	cout<<s.Dequeue()<<"\t"; s.Print();
	cout<<s.Dequeue()<<"\t"; s.Print();
	return 0;
}
