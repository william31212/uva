#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10739"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 1005


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif


	int times;
	// int **dp = new int*[MAXN];
	// for (int i = 0 ; i < MAXN ; i++)
	// 	dp[i] = new int[MAXN];
	int dp[MAXN][MAXN];
	string str;
	int cases = 1;

	scanf("%d",&times);

	while(times--)
	{
		memset(dp,0,sizeof(dp));
		cin >> str;

		for(int i = str.size()-1; i >= 0; i--)
			for(int j = i+1; j < str.size(); j++)
			{
				if(str[i] == str[j])
					dp[i][j] = dp[i+1][j-1];
				else
				{
					dp[i][j] = min( min(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1] ) +1;
				}
			}
		 printf("Case %d: %d\n",cases++,dp[0][str.size()-1]);
	}

	return 0;
}