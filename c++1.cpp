#include<bits/stdc++.h>
using namespace std;

class Stack{
	public:
		int a[1000];
		int size = 0;

void Push(int data){
	a[size]= data;
	size++;
}
void Print(){
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int Pop(){
	if(size==0){return -1;
	}
	else{
		int s = a[size-1];
		size = size -1;
		return s;
	}
}
};
int main(){
	Stack s;
	s.Push(1);	s.Print();
	s.Push(2);	s.Print();
	s.Push(3);	s.Print();
	s.Push(4);	s.Print();
	s.Push(5);	s.Print();
	cout<<s.Pop()<<endl;	s.Print();
	cout<<s.Pop()<<endl;	s.Print();
	cout<<s.Pop()<<endl;	s.Print();
	cout<<s.Pop()<<endl;	s.Print();
	cout<<s.Pop()<<endl;	s.Print();
	cout<<s.Pop()<<endl;	s.Print();
	return 0;
}
