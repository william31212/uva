#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11743.in","r",stdin);
	freopen("uva11743.out","w",stdout);
	#endif


	int times;
	char num;
	while(scanf("%d",&times) != EOF)
	{
		while(times--)
		{
			int k = 0;
			int arr[16];
			getchar();
			for (int i = 0; i < 19; ++i)
			{
				scanf("%c",&num);
				if (num == ' ')
				{
					continue;
				}
				else
				{
					arr[k] = (int)num - 48;
					k++;
				}
			}
			
			int even_sum = 0;
			int tmp = 0;
			for (int i = 0; i < 16; i += 2)
			{
				tmp = arr[i] * 2;
				while(tmp > 0)
				{
					even_sum += tmp%10;
					tmp /= 10;
				}

			}
			// printf("%d\n",even_sum);


			
			int odd_sum = 0;
			for (int i = 1; i <= 15; i += 2)
			{
				odd_sum += arr[i];
			}
			// printf("%d\n",odd_sum);


			if ( (odd_sum + even_sum) % 10 == 0 )
			{
				printf("Valid\n");
			}
			else
			{
				printf("Invalid\n");
			}
			
			
		}
	} 
	return 0;
}
	
