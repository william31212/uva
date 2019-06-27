#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10986"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

struct E
{
	int to,len;
};

int dp[20005];
vector <E> vec[20005];

void init()
{
	for (int i = 0; i < 20005; i++)
	{
		dp[i] = INF;
		vec[i].clear();
	}	
}
void addedge(int fr,int to,int len)
{
	vec[fr].PB({to, len});
	vec[to].PB({fr, len});
}

void dijkstra(int src)
{
	priority_queue<P, vector<P>, greater<P> > pq;
	//len,now
	pq.push({0,src});

	while(!pq.empty())
	{
		int now = pq.top().S;
		int length = pq.top().F;
		pq.pop();
		for(auto i : vec[now])
		{
			if( length + i.len < dp[i.to])
			{
				dp[i.to] = length + i.len;
				pq.push({dp[i.to], i.to});	
			}
		}
	}
	
}
int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times,cas = 1;
	scanf("%d",&times);

	while(times--)
	{
		init();
		int point,edge,fr,to;
		scanf("%d %d %d %d",&point,&edge,&fr,&to);

		for(int i = 0; i < edge; i++)
		{
			int f,t,l;
			scanf("%d %d %d",&f,&t,&l);
			addedge(f,t,l);
		}

		dijkstra(fr);

		if (to == fr)
			printf("Case #%d: 0\n", cas++);
		else if (dp[to] == INF)
			printf("Case #%d: unreachable\n", cas++);
		else
			printf("Case #%d: %d\n", cas++, dp[to]);
	}
	return 0;
}