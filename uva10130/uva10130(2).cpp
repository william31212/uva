#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva10130(2)"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);

	int wei[1005];
	int val[1005];
	int dp[1005];
	int peo[1005];


	for (int k = 0; k < times; ++k)
	{
		memset(wei,0,sizeof(wei));
		memset(val,0,sizeof(val));
		memset(dp,0,sizeof(dp));
		int mnt;
		scanf("%d",&mnt);
		for (int i = 0; i < mnt; ++i)
		{
			scanf("%d %d",&val[i],&wei[i]);
		}

		int people;
		scanf("%d",&people);

		int upper=0, tmp;
		for (int i = 0; i < people; ++i)
		{
			scanf("%d",&peo[i]);
			upper = max(upper,peo[i]);
		}

		for (int i = 0; i < mnt; ++i)
		{
			for (int j = upper; j >= wei[i]; --j)
			{
				dp[j] = max(dp[j - wei[i]] + val[i], dp[j]);
			}
		}

		int sum = 0;
		for (int i = 0; i < people; ++i)
		{
			sum += dp[peo[i]];
		}

		printf("%d\n",sum);
	}
	return 0;
}