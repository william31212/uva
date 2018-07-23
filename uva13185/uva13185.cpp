#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva13185.in","r",stdin);
	freopen("uva13185.out","w",stdout);
	#endif

	int times;
	scanf("%d",&times);

	while(times--)
	{
		int num;
		scanf("%d",&num);

		int sum = 0;
		for (int i = 1; i < num ; ++i)
		{
			if (num % i == 0)
			{
				sum += i;
			}
			else 
			{
				continue;
			}
		}

		if (sum == num)
		{
			printf("perfect\n");
		}

		else if (sum > num)
		{
			printf("abundant\n");
		}

		else if (sum < num)
		{
			printf("deficient\n");
		}

	} 

	return 0;
}
	
