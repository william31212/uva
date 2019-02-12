#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10819"
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

	int wei[1000];
	int val[1000];
	int dp[15000];

	int bag,mnt;
	while(~scanf("%d %d",&bag,&mnt))
	{
		memset(wei,0,sizeof(wei));
		memset(val,0,sizeof(val));
		dp[0] = 0;

		for (int i = 1; i < 15000; ++i)
		{
			dp[i] = -INF;
		}

		for (int i = 0; i < mnt; ++i)
		{
			scanf("%d %d",&wei[i],&val[i]);
		}

		for (int i = 0; i < mnt; ++i)
		{
			for (int j = 15000; j >= wei[i]; --j)//先全做
			{
				dp[j] = max(dp[j-wei[i]] + val[i] , dp[j]);
			}
		}

		int ans = 0;
        for(int i = 0; i < 15000 ; i++)
        {
			if ( (i > 2000 && i <= bag + 200) || i <= bag)//超過2000可以再拿200,跟花原本自己的錢
            {
            	ans = max(ans,dp[i]);
            }
        }

        printf("%d\n",ans);
	}
	return 0;
}