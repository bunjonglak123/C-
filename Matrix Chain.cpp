#include <bits/stdc++.h>
using namespace std;
int arr[] = { 10, 100, 5, 50, 1}; 
int n = sizeof(arr) / sizeof(arr[0]);
int MatrixChainOrder(int i, int j)
{
	if (i == j) {return 0; } 
	int min = 99999999999; 
	int count;
 		for (int k = i; k < j; k++)
	{
		count = MatrixChainOrder(i, k) + MatrixChainOrder(k + 1, j) + (arr[i - 1] * arr[k] * arr[j]); 
		if (count <min) {min = count;}  //MIN
	}
	return min; //RETURN MIN
}
int main()
{
	cout << MatrixChainOrder(1, n-1);
}

