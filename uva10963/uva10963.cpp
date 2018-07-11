#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10963.in","r",stdin);
	freopen("uva10963.out","w",stdout);
	#endif

	bool enter = 0;
	int times = 0;
	while( scanf("%d",&times) != EOF)
	{
		while(times--)
		{

			if (enter)
			{
				printf("\n");
			}

			int store;
			bool flag = 0, ansyes = 0 , ansno = 0;
			int amount = 0;
			scanf("%d",&amount);

			while( amount-- )
			{
					int y1,y2;
					scanf("%d %d",&y1,&y2);
					if (!flag)
					{
						store = y1 - y2;
						flag = 1;
					}
					else
					{
						if (store == (y1 - y2))
						{
							ansyes = 1;
						}
						else
						{
							ansno = 1;
						}
					}
			}

				if (ansyes && !ansno)
				{
					printf("yes\n");
				}

				if(ansno)
				{
					printf("no\n");
				}

				enter = 1;
		}
	}

	return 0;
}
	
