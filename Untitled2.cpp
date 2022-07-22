#include<iostream>
using namespace std;
int G1 = 10; //tuaplapaped
int L1 = 20; //tuaplapaped
void F()
{
	int G1 = 1; //tuaplapaped
	int L1 = 2; //tuaplapaped
	cout<<G1<<endl; //sadandkorkwam
	cout<<L1<<endl; //sadandkorkwam
}
int main()
{
	F();
	cout<<G1<<endl; //sadandkorkwam
	cout<<L1<<endl; //sadandkorkwam
	return 0;
}
