#include<stdio.h>

int main()
{
	double F ;
	double C ;
	scanf("%lf",&F);
	if(F>=32 && F<=4000)
	{
		C = ((F - 32)*5/9);
		printf("%.4lf",C);
	}
}
