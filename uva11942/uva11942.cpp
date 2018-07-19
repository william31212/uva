#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11942.in","r",stdin);
	freopen("uva11942.out","w",stdout);
	#endif


	int times;
	while(scanf("%d",&times) != EOF)
	{
		printf("Lumberjacks:\n");
		while(times--)
		{
			bool flag = 0;
			bool changebig = 0, changesmall = 0;
			int num,tmp;
			for (int i = 0; i < 10; ++i)
			{
				scanf("%d",&num);			
				if (!flag)
				{
					tmp = num;
					flag = 1;
					continue;
				}
				else
				{
					if (num > tmp)
					{
						changebig = 1;
						tmp = num;
					}
					else
					{
						changesmall = 1;
						tmp = num;
					}
				}
			}

			if (changebig && changesmall)
			{
				printf("Unordered\n");
			}
			else
			{
				printf("Ordered\n");
			}
		}	
	} 

	return 0;
}
	
