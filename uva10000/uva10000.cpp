#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10000"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int dp[105];
bool inque[105];
//P to,len
vector<P> G[105];

void init()
{
	for(int i = 0; i < 105; i++)
	{
		dp[i] = -INF;
		G[i].clear();
		inque[i] = false;
	}
		
}

void add_edge(int fr, int to)
{
	G[fr].PB(MP(to,1));
}


void spfa(int src)
{
	//len,src
	queue <int> que;
	dp[src] = 0;
	inque[src] = true;
	que.push(src);
	while(!que.empty())
	{
		int now = que.front();
		inque[now] = false;
		que.pop();
		for(auto i : G[now])
		{
			if(dp[now] + i.S > dp[i.F])
			{
				dp[i.F] = dp[now] + i.S;
				if(!inque[i.F])
				{
					que.push(i.F);
					inque[i.F] = true;
				}
			}
		}
	}
}

int cas = 1;
bool flag = 0;
void print_ans(int src)
{
	int ans = -INF;
	int ans_point = 0;
	for(int i = 0; i < 105; i++)
	{
		if(dp[i] > ans && dp[i] != INF)
		{
			ans = dp[i];
			ans_point = i;
		}
	}
	if(!flag)
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", cas++, src, ans, ans_point),flag=1;
	else
		printf("\nCase %d: The longest path from %d has length %d, finishing at %d.\n",cas++,src,ans,ans_point);
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int point,src;

	while(~scanf("%d",&point) && point)
	{
		scanf("%d",&src);
		int fr,to;
		init();
		while(scanf("%d %d",&fr,&to) && fr && to)
		{
			add_edge(fr, to);
		}
		spfa(src);
		print_ans(src);
	}
	printf("\n");

	return 0;
}