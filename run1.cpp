#include<stdio.h>
double tohour(double min,double sec){
	return (min/60)+(sec/3600);
}
double average(double distance,double time){
	return distance/time;
}
double convert(double speed){
	return speed*1.6;
}
int main(){
	double distance;
	double hour;
	double min;
	double sec;
	scanf("%lf %lf %lf %lf",&distance,&hour,&min,&sec);
	double time = tohour(min,sec)+hour;
	double speed = average(distance,time);
	double km = convert(speed);
	printf("%lf km/h\n",km);
}
