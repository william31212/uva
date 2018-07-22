#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva13178.in","r",stdin);
	freopen("uva13178.out","w",stdout);
	#endif


	int times;
	scanf("%d",&times);
	long long num;
	while(times--)
	{
		scanf("%lld",&num);
		if (num % 3 == 1)
		{
			printf("NO\n");
		}
		else 
		{
			printf("YES\n");
		}
	}

	return 0;
}
	
