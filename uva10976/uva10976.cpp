#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "p3"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)





int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int ans1[1000];
	int ans2[1000];
	while(scanf("%d",&num) != EOF)
	{
		int cnt = 0;
		for (int i = num+1; i <= num*2 ; ++i)
		{
			if (i-num == 1)
			{
				ans1[cnt] = num*i;	
				ans2[cnt] = num+1;
				cnt++;
			}
			if (__gcd(i-num,num*i) == 1)
			{
				continue;
			}
			else
			{
				int child = i - num;
				int mother = num * i;

				// printf("%d %d\n", child,mother);
				
				if (__gcd(mother,child) != 1 && mother % child == 0)
				{
					ans1[cnt] = mother/child;
					ans2[cnt] = i;
					cnt++;
				}
				
			}
		}

		printf("%d\n", cnt);
		for (int i = 0; i < cnt; ++i)
		{
			printf("1/%d = 1/%d + 1/%d\n",num,ans1[i],ans2[i]);
		}

	}

	return 0;
}