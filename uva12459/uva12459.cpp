#include <iostream>

using namespace std;


int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12459.in","r",stdin);
	freopen("uva12459.out","w",stdout);
	#endif

	long long f[81];

	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= 80 ; ++i)
	{
		f[i] = f[i-1] + f[i-2];
	}

	long long num;
	while(scanf("%lld",&num) != EOF && num)
	{
		printf("%lld\n",f[num]);
	} 

	return 0;
}
	
