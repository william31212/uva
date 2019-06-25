#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva437"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

struct Box
{
	int L,W,H;
};

bool cmp (const Box &lhs, const Box &rhs)
{
	if (lhs.L == lhs.L)
		return lhs.W < rhs.W;
	else
		return lhs.L < rhs.L;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int B,cas=1;
	while(~scanf("%d",&B) && B)
	{
		vector <Box> vec;
		int dp[1000];
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < B; i++)
		{
			int L,W,H;
			scanf("%d %d %d",&L,&W,&H);
			vec.PB({L, W, H});
			vec.PB({L, H, W});
			vec.PB({H, L, W});
			vec.PB({H, W, L});
			vec.PB({W, L, H});
			vec.PB({W, H, L});
		}
		sort(vec.begin(),vec.end(),cmp);

		//先存自行狀態
		for(int i = 0; i < vec.size(); i++)
			dp[i] = vec[i].H;

		int ans = -INF;
		for(int i = 0; i < vec.size(); i++)
		{	
			for(int j = i+1; j < vec.size(); j++)
			{
				if (vec[j].L > vec[i].L && vec[j].W > vec[i].W)
				{ 
					if (dp[i] + vec[j].H > dp[j])
					{
						dp[j] = dp[i] + vec[j].H;
					}
				}	
			}
			ans = max(dp[i], ans);
		}
		printf("Case %d: maximum height = %d\n",cas++,ans);
	}

	return 0;
}