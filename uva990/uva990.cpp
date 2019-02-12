#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva990"
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

	int bag,fuck;
	int mnt;
	int wei[1005];
	int val[1005];
	int dp[1005];
	bool flag = 0;

	stack < pair<int,int> > stk;

	while(~scanf("%d %d",&bag,&fuck))
	{
		if (!flag)
			flag = true;
		else
			printf("\n");


		scanf("%d",&mnt);
		memset(wei,0,sizeof(wei));
		memset(val,0,sizeof(val));
		bool dp2[mnt+5][1005];
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));


		for (int i = 1; i <= mnt; ++i)
		{
			scanf("%d %d",&wei[i],&val[i]);
		}

		for (int i = 1; i <= mnt; ++i)
		{
			for (int j = bag; j >= 3 * wei[i] * fuck ; --j)
			{
				if ( dp[j - (3 * wei[i] * fuck)] + val[i] > dp[j])
				{
					dp[j] = dp[j - (3 * wei[i] * fuck)] + val[i];
					dp2[i][j] = true;
				}
			}
		}


		for (int i = mnt , j = bag; i >= 1; i--)
		{
			if (dp2[i][j])
			{
				stk.push(MP(wei[i],val[i]));
				j -= 3 * wei[i] * fuck;
			}
		}

		printf("%d\n",dp[bag]);
		printf("%d\n",stk.size());
		while(!stk.empty())
		{
			printf("%d %d\n",stk.top().F,stk.top().S);
			stk.pop();
		}

	}
	return 0;
}