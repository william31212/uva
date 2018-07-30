#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva113.in","r",stdin);
	freopen("uva113.out","w",stdout);
	#endif

	double n,p;
	while(scanf("%lf",&n) != EOF)
	{
		scanf("%lf",&p);
		printf("%.0f\n",pow(p,1.0/n));
	}

	return 0;
}
	
