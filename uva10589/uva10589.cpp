#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10589.in","r",stdin);
	freopen("uva10589.out","w",stdout);
	#endif
	int N=0;
	double a=0;
	double A,B,C,D;
	while(cin >> N >> a){
		if(!N && !a)
			break;
		int M=0;
		double x,y;
		for(int i=0;i<N;i++){
			cin >> x >> y;
			A = sqrt((x*x)+(y*y));
			B = sqrt((x-a)*(x-a) + (y)*(y));			
			C = sqrt((x)*(x) + (y-a)*(y-a));			
			D = sqrt((x-a)*(x-a) + (y-a)*(y-a));						
			if(A<=a && B<=a && C<=a && D<=a)
				M++;
		}
		printf("%.5f\n",(double)((double)M/(double)N)*(double)a*(double)a);
	}
}