#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10066"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int dp[105][105];


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	
	
	int a,b;
	int cas = 1;
	bool enter = false;

	while(~scanf("%d %d",&a,&b) && a && b)
	{
		vector<int> vec1;
		vector<int> vec2;
		vec1.PB(0);
		vec2.PB(0);
		for(int i = 0, tmp = 0; i < a && scanf("%d",&tmp); i++)
			vec1.PB(tmp);
		for (int i = 0, tmp = 0; i < b && scanf("%d",&tmp); i++)
			vec2.PB(tmp);

		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= vec1.size(); i++)
			for(int j = 1; j <= vec2.size(); j++)
			{
				if (vec1[i] == vec2[j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		if (!enter)
		{
			printf("Twin Towers #%d\nNumber of Tiles : %d", cas++, dp[a][b]);
			enter = true;
		}
		else
			printf("\n\nTwin Towers #%d\nNumber of Tiles : %d", cas++, dp[a][b]);
	}
	printf("\n");
	printf("\n");

	return 0;
}