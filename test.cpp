#include <bits/stdc++.h>
using namespace std;


int max(int a, int b) { return (a > b) ? a : 
b; }


int knapSack(int bag, int w[], int v[], int i)
{

	// Base Case
	if (i == 0 || bag == 0)
		return 0;

	if (w[i - 1] > bag)
		return knapSack(bag, w, v, i - 1);

	else
		return max(v[i - 1]+ knapSack(bag-w[i-1],w, v, i - 1),knapSack(bag, w, v, i - 1));
}

// Driver code
int main()
{
	int w[5] = {1,5,3,2,4};
	int v[5] = {5,9,10,6,7};;
	int bag = 10;
	int ans[5] = {0,0,0,0,0};
	int i = sizeof(v) / sizeof(v[0]);
	cout << max(v[i - 1]+ knapSack(bag-w[i-1],w, v, i - 1),knapSack(bag, w, v, i - 1));
	cout << endl;
	cout << knapSack(bag, w, v, i);
	return 0;
}

// This code is contributed by rathbhupendra

