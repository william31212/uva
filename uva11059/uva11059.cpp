#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11059.in","r",stdin);
	freopen("uva11059.out","w",stdout);
	#endif

	int count = 1;
	int times = 0;

	while( scanf("%d",&times) != EOF && times)
	{

		long long arr[20];

		for (int i = 0; i < times; ++i)
		{
			scanf("%lld",&arr[i]);
		}

		long long maxnum = 0;

		for (int i = 0; i < times; ++i)
		{
			long long tmp = 1;

			for (int j = i ; j < times ; ++j)
			{
				tmp *= arr[j];

				if (tmp > maxnum)
					maxnum = tmp;
			}
		}

		printf("Case #%d: The maximum product is %lld.\n\n",count,maxnum);
		count++;
	}

	return 0;
}
	