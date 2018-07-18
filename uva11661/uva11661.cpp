#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11661.in","r",stdin);
	freopen("uva11661.out","w",stdout);
	#endif

	//簡單的DP
	char str[2000000];
	int times;
	while( scanf("%d",&times) != EOF && times)
	{
		bool flag = 0;
		int record = 2000002;
		int maxx = 2000002;
		scanf("%s",str);

		for (int i = 0; i < times; ++i)
		{
			if (str[i] == 'Z')
			{
				printf("0\n");
				flag = 0;
				break;
			}

			if (str[i] == 'D')
			{
				record = i;
			}

			if (str[i] == 'R')
			{ 
				flag = 1;
				if (maxx > abs(i - record) && record != 2000002)
				{
					maxx = abs(i - record);
				}
			}

		}

		record = 2000002;

		for (int j = times - 1; j >= 0 ; j--)
		{
			if (str[j] == 'Z')
			{
				flag = 0;
				break;
			}
			
			if (str[j] == 'D')
			{
				record = j;
			}

			if (str[j] == 'R')
			{ 
				flag = 1;
				if (maxx > abs(j - record) && record != 2000002)
				{

					maxx = abs(j - record);
				}
			}
		}

		if (flag)
		{
			printf("%d\n",maxx);
		}
	}

	return 0;
}
	
