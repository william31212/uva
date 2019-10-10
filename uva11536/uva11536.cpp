#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11536"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int dp[1000005];
int cnt[1005];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t,kase = 1;
	memset(dp,0,sizeof(dp));
	cin >> t;
	while(t--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		dp[1] = 1,dp[2] = 2,dp[3] = 3;

		for (int i = 4; i <= n; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % m + 1;
		}

		int l=1,r=0,cnt[1010],tot=0;
		int ans =INT_MAX;
		memset(cnt,0,sizeof(cnt));

		while(r <= n)
		{
			if(tot == k)
			{
				//刪除我自己這格
				cnt[dp[l]]--;
				if (cnt[dp[l]] == 0 && dp[l] >= 1 && dp[l] <= k)
					tot--;
				//拔掉現在這格，所以l要往隔壁一格
				l++;
				if (tot == k)
					ans = min(ans, r-l+1);
			}
			else
			{
				r++;
				cnt[dp[r]]++;
				if(cnt[dp[r]] == 1 && dp[r] >= 1 && dp[r] <= k)
					tot++;
				if(tot == k)
					ans = min(ans, r-l+1);
			}
		}

		if(ans == INT_MAX)
			printf("Case %d: sequence nai\n",kase++);
		else
			printf("Case %d: %d\n",kase++,ans);

	}

	return 0;
}