#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10342"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 1000

struct node
{
	int u;
	int dis;
	bool operator < (const node &rhs) const
	{
		return dis > rhs.dis;
	}
};

vector<node> G[MAXN];
//from A to B, short path
int D[MAXN][MAXN][2];
int e, p, q;
int kase = 0;

void dijk(int s)
{
	priority_queue<node> pq;

	for (auto i : G[s])
	{
		pq.push((node){i.u, i.dis});
	}

	while(!pq.empty())
	{
		int u = pq.top().u;
		int dis = pq.top().dis;
		pq.pop();

		if(D[s][u][0] == 0)
			D[s][u][0] = dis;
		else
		{
			if(D[s][u][0] > dis)
			{
				D[s][u][1] = D[s][u][0];
				D[s][u][0] = dis;
			}
			else if (D[s][u][0] == dis)
				continue;
			else if (D[s][u][1] == 0 || D[s][u][1] > dis)
			{
				D[s][u][1] = dis;
			}
			else
				continue;
		}

		for(auto i : G[u])
		{
			pq.push((node){i.u, dis + i.dis});
		}

	}


}

void init()
{
	memset(D,0,sizeof(D));
	for(int i = 0; i < p; i++)
		G[i].clear();
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	while(cin >> p >> e)
	{
		init();
		int a,b,d;
		for(int i = 0; i < e; i++)
		{
			cin >> a >> b >> d;
			G[a].push_back((node){b,d});
			G[b].push_back((node){a,d});
		}

		printf("Set #%d\n",++kase);

		for(int i = 0; i < p; i++)
			dijk(i);

		cin >> q;

		while(q--)
		{
			cin >> a >> b;
			if(a != b)
			{
				if(D[a][b][1])
					printf("%d\n",D[a][b][1]);
				else
					printf("?\n");
			}
			else
			{
				if(D[a][b][0])
				{
					//default is zero, so we get in D[0]
					printf("%d\n",D[a][b][0]);
				}
				else
					printf("?\n");
			}
		}
	}
	return 0;
}