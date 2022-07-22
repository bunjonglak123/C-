#include<stdio.h>
int main(){
	int sec = 5*365*24*60*60;
	int birth = sec/7;
	int death = sec/13;
	int immi = sec/45;
	int pop = (312032486+birth-death+immi);
	printf("%d\n",pop);
}
