#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10209.in","r",stdin);
	freopen("uva10209.out","w",stdout);
	#endif
	
	double a=0;
	double pi = 2 * acos(0);
	double area = sqrt(3)/4;
	double tmp=0;
	double first=0;
	double eyes=0;
	double second=0;
	double fuck=0;
	double third=0;
	while(cin >> a){
		tmp = 2*((a * a * pi)/6 - (a * a * area));
		tmp += (area * a * a);
		tmp = (a*a*pi)/4 - tmp;
		first = a*a - (4*tmp);
		eyes = ((a*a*pi/4) - (a*a/2))*2;
		second = (eyes - first)*2;
		fuck = second/4;
		third = (((a*a)-(a*a*pi/4)) - fuck)*2;
		printf("%.3f %.3f %.3f\n",first,second,third);
	}


	return 0;
}