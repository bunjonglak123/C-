#include<stdio.h>

int main()
{
	double f = 0;
	double c = ((f - 32)*5/9);
	scanf("%f",&f);
	if(f>=32 && f<=4000)
	{
		printf("%.4f",c);
	}
}
