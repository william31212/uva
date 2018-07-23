#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva13187.in","r",stdin);
	freopen("uva13187.out","w",stdout);
	#endif

	int times;
	scanf("%d",&times);

	while(times--)
	{	
		long long num;
		scanf("%lld",&num);
		printf("%lld\n", (num+1) * (num+1) - 1);
	}

	return 0;
}
	
