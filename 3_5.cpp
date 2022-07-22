#include<bits/stdc++.h>
using namespace std;

int ans[5] = {0,0,0,0,0};
int size = 5;
int w[5] = {1,5,3,2,4};
int v[5] = {5,9,10,6,7};
int bag = 10;
int sumvfinal = 0;
int sumwfinal = 0;


void brute (int j) {

	if (j == size) {
		int sumw =0;
		int sumv = 0;
		for(int i=0 ; i<size; i++) {
			if(ans[i] == 1) {
				sumw = sumw + w[i];
				sumv = sumv + v[i];
				}
			}
		if(sumw <= bag ){
			if(sumv>sumvfinal){
				
			for(int i=0 ; i<size; i++) {
				cout<<ans[i]<<" ";
			}
			sumvfinal = sumv;
			cout<<endl;
			}
		}
	}

	else {
		int num = j+1;
		ans[j] = 0;
		brute(num);
		ans[j] = 1;
		brute(num);
	}
}
int main() {
	brute(0);
	cout<<sumvfinal;
	return 0;
}

