#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11172.in","r",stdin);
	freopen("uva11172.out","w",stdout);
	#endif

	int times = 0; 
	while (scanf("%d",&times) != EOF && times)
	{
		while(times--){

			long long int a = 0,b = 0;
			scanf("%lld",&a);
			scanf("%lld",&b);

			if(a > b)
			{
				printf(">\n");
			}
			if(a == b)
			{
				printf("=\n");
			}
			if(a < b)
			{
				printf("<\n");
			}

		}
	}
	return 0;
}
	