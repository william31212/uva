#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10917"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 100000

struct node
{
	int to, dis;
};

vector <node> G[MAXN];
int preve[MAXN];
int dis[MAXN];
//從起點到dp[i]點總共有幾條不同路
int dp[MAXN];
int ans = 0;

void init()
{
	ans = 0;
	for(int i = 0; i < MAXN; i++)
	{
		G[i].clear();
		dis[i] = INF;
		preve[i] = i;
		dp[i] = 0;
	}
}

void add_edge(int fr, int to, int len)
{
	G[fr].PB({to, len});
	G[to].PB({fr, len});
}

void dijkstra(int src)
{
	priority_queue<P,vector<P>, greater<P>> pq;
	dis[src] = 0;
	//len,now
	pq.push(MP(0,src));
	
	while(!pq.empty())
	{
		int len = pq.top().F;
		int now = pq.top().S;
		pq.pop();
		for (auto i : G[now])
		{
			if(dis[now] + i.dis < dis[i.to])
			{
				dis[i.to] = dis[now] + i.dis;
				preve[i.to] = now;
				pq.push(MP(dis[i.to], i.to));
			}
		}
	}
}


int dfs(int u)
{
	if(u == 2)
		return 1;
	
	if(dp[u])
	{
		return dp[u];
	}
	
	for(auto i : G[u])
	{
		if(dis[i.to] < dis[u])
		{
			dp[u] += dfs(i.to);
		}
	}

	return dp[u];
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int point,road;

	while(~scanf("%d",&point) && point)
	{
		scanf("%d", &road);
		init();
		for(int i = 0; i < road ; i++)
		{
			int fr,to,len;
			scanf("%d %d %d\n",&fr,&to,&len),add_edge(fr,to,len);
		}
		dijkstra(2);
		dfs(1);
		printf("%d\n",dfs(1));
	}

	return 0;
}