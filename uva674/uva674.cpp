#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva674"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int dp[8000];
int coin[5] = {1,5,10,25,50};

void build()
{	
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = coin[i]; j < 8000; ++j)
		{
			dp[j] += dp[j-coin[i]];
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
	int num;
	while(scanf("%d",&num) != EOF)
	{
		printf("%d\n",dp[num]);
	}

	return 0;
}