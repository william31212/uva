#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1213"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool visit[1500];
int prime[1500];
int prime_cnt = 0;
int dp[1205][15][2];


void build()
{
	memset(visit,true,sizeof(visit));

	for (int i = 2; i < 1200; ++i)
	{
		if (visit[i])
		{
			prime[prime_cnt++] = i;
			for (int j = i + i; j < 1200; j += i)
			{
				visit[j] = false;
			}
		}
	}
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	build();
	
	dp[0][0][0] = 1;
	for (int k = 0; k < prime_cnt; ++k)
	{
		for (int i = 1; i <= 1120; i++)
		{
			for (int j = 1; j <= 14; ++j)
			{
				if (i >= prime[k])
				{
					dp[i][j][1] = dp[ i-prime[k] ][j-1][0] + dp[i][j][1];
				}
				
			}
		}

		for (int i = 1; i <= 1120; i++)//0,1 package
		{
			for (int j = 1; j <= 14; ++j)//range
			{
				dp[i][j][0] = dp[i][j][1];
				
			}
		}
	}

	
	int n,k;

	while(~scanf("%d %d",&n,&k))
	{
		if (!n && !k)
			break;
		printf("%d\n",dp[n][k][1]);
	}

	return 0;
}