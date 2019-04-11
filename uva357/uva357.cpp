#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva357"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define LL long long

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	LL cent;
	LL dp[40000];
	LL coin[5] = {1,5,10,25,50};
	memset(dp,0,sizeof(dp));
	dp[0] = 1;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 1; j < 30005; ++j)
		{
			if(j >= coin[i])
			{
				dp[j] += dp[j-coin[i]];
			}
		}
	}


	while(cin >> cent)
	{
		if(dp[cent] == 1)
			printf("There is only %lld way to produce %lld cents change.\n", dp[cent], cent);
		else
			printf("There are %lld ways to produce %lld cents change.\n", dp[cent], cent);
	}

	return 0;
}