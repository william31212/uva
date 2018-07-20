#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12405.in","r",stdin);
	freopen("uva12405.out","w",stdout);
	#endif



	int times;
	while(scanf("%d",&times) != EOF)
	{
		int cas = 1;
		while(times--)
		{
			int num[110];
			int length;
			int count = 0;
			fill(num,num+110,0);

			scanf("%d",&length);
			getchar();
			for (int i = 0; i < length; ++i)
			{
				char tmp;
				scanf("%c",&tmp);
				if (tmp == '.')
				{
					num[i] = 0;
				}
				else if(tmp == '#')
				{
					num[i] = 1;
				}
			}

			// for (int i = 0; i < length; ++i)
			// {
			// 	printf("%d ",num[i]);
			// }
			for (int i = 0; i < length; ++i)
			{
				if(num[i] == 0 && i <= length - 3)
				{
					num[i] = 1;
					num[i+1] = 1;
					num[i+2] = 1;
					count++;
				}
				else if (num[i] == 0 && i == length - 2)
				{
					if (num[i+1] == 1)
					{
						count++;
						continue;
					}
					else if (num[i+1] == 0)
					{
						num[i] = 1;
						num[i+1] = 1;
						count++;
					}
				}

				else if (num[i] == 0 && i == length - 1)
				{
					num[i] = 1;
					count++;
				}
			}

			printf("Case %d: %d\n", cas++ , count);
		}
	} 
	return 0;
}
	