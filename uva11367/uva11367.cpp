#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11367"
#define SIZEM 1005
#define INF 1e9

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)


struct Edge
{
	int from,to,dis;
};

struct node
{
	int point,oil,cost;//要到那個點，剩餘油量，已花費
	bool operator < (const node &input) const
	{
		return cost > input.cost;//價格少的為優先
	}
};
int city,road;
vector <Edge> edges;
vector <int> G[SIZEM];
bool visited[SIZEM][SIZEM];
int oil_price[SIZEM];
int dp[SIZEM][SIZEM];

void Addedge(int from,int to,int dis)
{
	edges.push_back((Edge){from,to,dis});
	edges.push_back((Edge){to,from,dis});
	int m = edges.size();

	G[from].push_back(m-2);
	G[to].push_back(m-1);
}

int run_dijkstra(int oil_size,int start,int end)
{
	priority_queue <node> que;
	// memset(dp,INF,sizeof(dp));
	for (int i = 0; i < SIZEM; ++i)
	{
		for (int j = 0; j < SIZEM; ++j)
		{
			dp[i][j] = INF;
		}
	}
	memset(visited,0,sizeof(visited));
	dp[start][0] = 0;

	que.push((node){start,0,dp[start][0]});


	while(!que.empty())
	{
		node cur = que.top();
		que.pop();

		int top_point = cur.point;
		int top_oil = cur.oil;

		if (visited[top_point][top_oil])
			continue;

		visited[top_point][top_oil] = true;

		for (int i = 0; i < G[top_point].size(); ++i)
		{
			int too = edges[ G[top_point][i] ].to;
			int d = edges[ G[top_point][i] ].dis;
			
			if (d > top_oil)//油不夠
				continue;
			if (dp[too][top_oil - d] > dp[top_point][top_oil])//油夠了
			{
				dp[too][top_oil - d] = dp[top_point][top_oil];//直接跑
				que.push((node){ too , top_oil - d , dp[too][top_oil - d]});
			}
		}

		if (top_oil < oil_size && dp[top_point][top_oil+1] > dp[top_point][top_oil] + oil_price[top_point])//加油
		{
			dp[top_point][top_oil + 1] = dp[top_point][top_oil] + oil_price[top_point];//+1公升若便宜
			que.push((node){top_point , top_oil + 1, dp[top_point][top_oil+1]});//敬請排隊
		}
	}


}



int main()
{

	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	while(cin >> city >> road)
	{
		for (int i = 0; i < city; ++i)
		{
			cin >> oil_price[i];
		}
		int begin,end,dis;
		for (int i = 0; i < road; ++i)
		{
			cin >> begin >> end >> dis;
			Addedge(begin,end,dis);
		}
		


		int question;
		int oil_size;
		int question_start,question_end;
		cin >> question;

		while(question--)
		{
			cin >> oil_size >> question_start >> question_end;
			run_dijkstra(oil_size,question_start,question_end);
			// for (int i = 0; i < question_end; ++i)
			// {
			// 	for (int j = 0; j < ; ++j)
			// 	{
			// 		cout << dp[i][j] << " ";
			// 	}
			// 	cout << '\n';
			// }
			if (dp[question_end][0] == INF)
			{
				printf("impossible\n");
			}
			else
			{
				printf("%d\n",dp[question_end][0]);
			}
		}


	}

	return 0;
}