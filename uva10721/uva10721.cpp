#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10721"
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

	int n,k,m;
	LL dp[100][100];

	while(~scanf("%d %d %d",&n,&k,&m))
	{
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i = 1; i <= k; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				if (i == 1 && j <= m && j != 0)
					dp[i][j] = 1;
				else
				{
					for(int q = 1; q <= m; q++)
						if (j-q >= 0)
							dp[i][j] += dp[i-1][j-q];
				}
			}
		}
		printf("%lld\n",dp[k][n]);
	}

	return 0;
}