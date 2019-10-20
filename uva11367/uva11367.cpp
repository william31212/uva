#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11367"
#define MAXN 1005
#define PB push_back
#define P pair<int, int>
#define F first
#define S second

#define USE_CPPIO()               \
	ios_base::sync_with_stdio(0); \
	cin.tie(0)

struct State
{

	int fr, oil, cost;
	friend bool operator<(const State &lhs, const State &rhs)
	{
		return lhs.cost > rhs.cost;
	}
};

int city, road, p[MAXN], q, c, s, e;
int vis[MAXN][MAXN], dp[MAXN][105];
vector<P> G[MAXN];

void debug()
{
	for (int i = 0; i < city; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	printf("------------------------\n");
}

void add_edge(int fr, int to, int len)
{
	G[fr].PB({to, len});
	G[to].PB({fr, len});
}

int dijk(int s, int e, int c)
{
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < city; i++)
		for (int j = 0; j <= c; j++)
			dp[i][j] = INT_MAX;
	priority_queue<State> pq;

	//to, oil, cost
	dp[s][0] = 0;
	pq.push({s, 0, dp[s][0]});

	while (!pq.empty())
	{
		State cur = pq.top();
		pq.pop();

		if (vis[cur.fr][cur.oil])
			continue;

		vis[cur.fr][cur.oil] = 1;

		for (auto i : G[cur.fr])
		{
			int to = i.F;
			int road_len = i.S;

			//油不夠
			if (cur.oil < road_len)
				continue;

			// 如果現在油量能支撐你跑到下個點，錢又花得比剛剛少，就取代，再把狀態拿到pq嘗試
			if (dp[cur.fr][cur.oil] < dp[to][cur.oil - road_len])
			{
				dp[to][cur.oil - road_len] = dp[cur.fr][cur.oil];
				pq.push({to, cur.oil - road_len, dp[to][cur.oil - road_len]});
			}
		}

		//油箱容量沒爆，加看看一滴油，再把狀態推進pq裡
		if (cur.oil < c && dp[cur.fr][cur.oil + 1] > dp[cur.fr][cur.oil] + p[cur.fr])
		{
			dp[cur.fr][cur.oil + 1] = dp[cur.fr][cur.oil] + p[cur.fr];
			pq.push({cur.fr, cur.oil + 1, dp[cur.fr][cur.oil + 1]});
		}

		// debug();
	}

	return dp[e][0];
}

int main()
{
#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
#endif

	while (~scanf("%d %d", &city, &road))
	{
		memset(p, 0, sizeof(p));
		for (int i = 0; i < MAXN; i++)
			G[i].clear();

		for (int i = 0; i < city; i++)
			scanf("%d", &p[i]);

		for (int i = 0, a, b, c; i < road; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			add_edge(a, b, c);
		}

		scanf("%d", &q);

		for (int i = 0; i < q; i++)
		{
			scanf("%d %d %d", &c, &s, &e);
			int ans = dijk(s, e, c);
			if (ans == INT_MAX)
				printf("impossible\n");
			else
				printf("%d\n", ans);
		}
	}

	return 0;
}