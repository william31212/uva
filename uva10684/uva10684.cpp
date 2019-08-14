#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10684"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 50000

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	while(~scanf("%d",&times) && times)
	{
		int dp[MAXN];
		int arr[MAXN];
		for (int i = 0; i < times; i++)
			scanf("%d", &arr[i]);

		int ans = dp[0] = arr[0];
		for(int i = 1; i < times; i++)
		{
			dp[i] = max(arr[i],dp[i-1]+arr[i]);
			ans = max(dp[i], ans);
		}
		
		if(ans <= 0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n", ans);
	}
	return 0;
}