#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10812.in","r",stdin);
	freopen("uva10812.out","w",stdout);
	#endif
	int times = 0;
	scanf("%d",&times);

	while(times--)
	{
		long long sum = 0, dif = 0;
		long long x = 0, y = 0;
		scanf("%lld %lld",&sum,&dif);
		
		x = (sum+dif)/2;
		y = (sum-dif)/2;
		if( x >= 0 && y >= 0 && (sum+dif)%2 == 0 && (sum-dif)%2 == 0)
		{
			if(x > y)
				printf("%lld %lld\n",(long long)x,(long long)y);
			else
				printf("%lld %lld\n",(long long)y,(long long)x);
		}
		else
			printf("impossible\n");
	}
	return 0;
}
	
