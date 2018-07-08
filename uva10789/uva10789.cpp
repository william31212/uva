#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//udebug 對持續不能 AC
int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10789.in","r",stdin);
	freopen("uva10789.out","w",stdout);
	#endif
	int times = 0;
	int count = 1;
	scanf("%d",&times);
	while(times--)
	{
		bool flag = 1;
		bool empty = 0;
		int ascii[128] = {0};
		char test[2001];
		scanf("%s",test);
		for (unsigned int i = 0; i < strlen(test); ++i)
		{
			ascii[(int)test[i]]++; 
		}

		printf("Case %d: ", count);
		count++;

		for (int i = 0; i < 128; ++i)
		{
			flag = 1;
			if (ascii[i] == 1 || ascii[i] == 0)
			{
				flag = 0;
			}

			for (int j = 2; j < ascii[i]; j++)
			{
				if(ascii[i] % j == 0)
				{
					flag = 0;
					break;
				}
			}

			if(flag)
			{
				printf("%c",(char)i);
				empty = 1;
			}
		}

		if (!empty)
		{
			printf("empty\n");
		}
		else
		{
			printf("\n");
		}

	}

	return 0;
}
	