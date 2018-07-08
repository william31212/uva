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
		int num[10] = {0};
		int alp_small[26] = {0};
		int alp_big[26] = {0};
		char test[2001];
		scanf("%s",test);
		for (unsigned int i = 0; i < strlen(test); ++i)
		{
			if(48<=(int)test[i] && (int)test[i]<=57)
			{
				num[(int)test[i]-48]+=1;
			}
			if(65<=(int)test[i] && (int)test[i]<=96)
			{
				alp_big[(int)test[i]-65]+=1;
			}
			if(97<=(int)test[i] && (int)test[i]<=122)
			{
				alp_small[(int)test[i]-97]+=1;
			}
		}

		printf("Case %d: ", count);
		count++;

		for (int i = 0; i < 10; ++i)
		{
			flag = 1;
			if (num[i] == 1 || num[i] == 0)
			{
				flag = 0;
			}
			for (int j = 2; j < num[i]; j++)
			{
				if(num[i] % j == 0)
					flag = 0;
					break;
			}
			if(flag)
			{
				printf("%c",(char)(i+48));
				empty = 1;
			}
		}

		
		for (int i = 0; i < 26; ++i)
		{
			flag = 1;
			if (alp_big[i] == 1 || alp_big[i] == 0)
			{
					flag = 0;
			}
			for (int j = 2; j < alp_big[i]; j++)
			{
				if(alp_big[i] % j == 0)
					flag = 0;
					break;
			}
			if(flag)
			{
				printf("%c",(char)(i+65));
				empty = 1;
			}
		}

		
		for (int i = 0; i < 26; ++i)
		{
			flag = 1;
			if (alp_small[i] ==1 || alp_small[i] == 0)
			{
				flag = 0;
			}
			for (int j = 2; j < alp_small[i]; j++)
			{
				if(alp_small[i] % j == 0)
					flag = 0;
					break;
			}
			if(flag)
			{
				printf("%c",(char)(i+97));
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
	