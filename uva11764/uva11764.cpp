#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11764.in","r",stdin);
	freopen("uva11764.out","w",stdout);
	#endif


	int times;
	while(scanf("%d",&times) != EOF)
	{
		int count = 1;
		while(times--)
		{
			int tmp;
			int length,num;
			int high = 0,low = 0;
			bool flag = 0;

			scanf("%d",&length);

			while(length--)
			{
				scanf("%d",&num);

				if (!flag)
				{
					tmp = num;
					flag = 1;
					continue;
				}

				if (tmp > num)
				{
					tmp = num;
					low++;
					continue;
				}

				if (tmp < num)
				{
					tmp = num;
					high++;
					continue;
				}
			}
			
			printf("Case %d: %d %d\n",count++,high,low);
		}
	} 
	return 0;
}
	
