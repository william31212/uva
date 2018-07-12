#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11204.in","r",stdin);
	freopen("uva11204.out","w",stdout);
	#endif

	int times;
	while( scanf("%d",&times) != EOF)
	{
			while(times--)
			{
				int arr[40];
				fill(arr,arr+40,0);
				int inst,people;
				int tmp;

				scanf("%d %d",&inst,&people);


				for (int i = 0; i < people; ++i)
				{
					for (int j = 0; j < inst; ++j)
					{

						scanf("%d",&tmp);

						if(tmp == 1)
						{
							arr[j]++;
						}
					}
				}



				int sum = 1;
				for (int i = 0; i < 40; ++i)
				{
					if (arr[i] >= 1)
					{
						sum *= arr[i];
					}
						
				}
				printf("%d\n", sum);
			}

	}
	return 0;
}
	