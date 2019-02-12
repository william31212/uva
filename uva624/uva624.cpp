#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva624"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int len,n;
	int cd[25];
	int dp[25][1500];
	stack <int> stk;

	while(scanf("%d %d",&len,&n) != EOF)
	{
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&cd[i]);
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= len; ++j)
			{
				if (j >= cd[i])
				{
					dp[i][j] = max(dp[i-1][j - cd[i]] + cd[i] , dp[i-1][j]);
				}
				else
					dp[i][j] = dp[i-1][j];
			}
		}

		for (int i = n , j = len; i > 0 && j > 0 ; i--)
		{
			if (dp[i][j] == dp[i-1][j])
			{
				continue;
			}
			else
			{
				stk.push(cd[i]);
				j -= cd[i];
			}

		}

		while(!stk.empty())
		{
			printf("%d ",stk.top());
			stk.pop();
		}

		printf("sum:%d\n",dp[n][len]);

	}
	return 0;
}