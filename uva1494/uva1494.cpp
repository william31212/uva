#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1494"
#define MAXN 1005
#define PB push_back
#define MP make_pair
#define F first
#define S second

#define USE_CPPIO()               \
	ios_base::sync_with_stdio(0); \
	cin.tie(0)

struct Edge
{
	int fr, to;
	double len;
	bool operator<(const Edge &rhs) const
	{
		return len < rhs.len;
	}
};

int X[MAXN], Y[MAXN], P[MAXN];
int kru[MAXN], num[MAXN];
vector<Edge> edges;
//to,len
vector<pair<int, double>> G[MAXN];
double Max_cost[MAXN][MAXN];
bool vis[MAXN];

double dis(int x1, int y1, int x2, int y2)
{
	return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

void init()
{
	memset(X, 0, sizeof(X));
	memset(Y, 0, sizeof(Y));
	memset(P, 0, sizeof(P));
	memset(Max_cost, 0, sizeof(Max_cost));
	edges.clear();
	for (int i = 0; i < MAXN; i++)
		kru[i] = i, num[i] = 1, G[i].clear();
}

void dfs(int u, int now, double Max_num)
{
	Max_cost[u][now] = max(Max_num, Max_cost[u][now]);
	vis[now] = 1;
	for (auto i : G[now])
	{
		double tmp = max(Max_num, i.S);
		if (!vis[i.F])
			dfs(u, i.F, tmp);
	}
}

void debug(double sum, int n)
{
	printf("%.lf\n", sum);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%.lf ", Max_cost[i][j]);
		}
		printf("\n");
	}
}

int main()
{
#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
#endif

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		init();
		for (int i = 1; i <= n; ++i)
		{
			int tmp1, tmp2, tmp3;
			cin >> tmp1 >> tmp2 >> tmp3;
			X[i] = tmp1, Y[i] = tmp2, P[i] = tmp3;
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j < i; ++j)
			{
				double L = dis(X[i], Y[i], X[j], Y[j]);
				edges.push_back({i, j, L});
			}
		sort(edges.begin(), edges.end());

		// MST
		double Sum = 0;
		for (int i = 0; i < edges.size(); i++)
		{
			int a = edges[i].fr;
			int b = edges[i].to;
			double l = edges[i].len;
			// printf("%d %d %.lf\n",a,b,l);
			while (a != kru[a])
				a = kru[a];
			while (b != kru[b])
				b = kru[b];

			if (a != b)
			{
				if (num[b] >= num[a])
				{
					num[b] += num[a];
					kru[a] = b;
				}
				else
				{
					num[a] += num[b];
					kru[b] = a;
				}
				G[b].PB(MP(a, l));
				G[a].PB(MP(b, l));
				Sum += l;
			}
		}

		double ans = 0;
		for (int i = 1; i <= n; i++)
			memset(vis, 0, sizeof(vis)), dfs(i, i, 0);

		// debug(Sum,n);

		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max((double)(P[i] + P[j]) / (Sum - Max_cost[i][j]), ans);
		printf("%.2lf\n", ans);
	}
	return 0;
}