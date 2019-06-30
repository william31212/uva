#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva1175"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 1005

struct BOY
{
	int state = 1;
};


int boy[MAXN][MAXN];
int girl[MAXN][MAXN];
int chg_state[MAXN][MAXN];
int girl_love[MAXN];
int ans[MAXN];

int PK(int a, int b, int fm)
{
	if (chg_state[fm][a] < chg_state[fm][b])
		return 1;
	else
		return 2;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	bool flag = 0;
	scanf("%d",&times);

	while(times--)
	{
		if(!flag)
			flag = 1;
		else
			cout << '\n';
		
		int peo;
		scanf("%d",&peo);

		BOY B[MAXN];
		memset(boy,0,sizeof(boy));
		memset(girl,0,sizeof(girl));
		memset(chg_state, 0, sizeof(chg_state));
		memset(girl_love,-1,sizeof(girl_love));
		queue <int> que;

		for(int i = 1; i <= peo; i++)
		{
			for (int j = 1; j <= peo; j++)
				scanf("%d", &boy[i][j]);
			que.push(i);
		}
			
		for (int i = 1; i <= peo; i++) 
			for (int j = 1; j <= peo; j++)
				scanf("%d", &girl[i][j]);

		for (int i = 1; i <= peo; i++)
			for (int j = 1; j <= peo; j++)
				chg_state[i][girl[i][j]] = j;

		while(!que.empty())
		{
			int now = que.front();
			que.pop();
			int women = boy[now][B[now].state];
			if(girl_love[women] == -1)
			{
				girl_love[women] = now;
			}
			else
			{
				if (PK(now, girl_love[women], women) == 1)
				{
					B[girl_love[women]].state++;
					que.push(girl_love[women]);
					girl_love[women] = now;
				}
				else
				{
					B[now].state++;
					que.push(now);
				}
			}

		}

		for (int i = 1; i <= peo; i++)
			ans[girl_love[i]] = i;
		for	(int i = 1; i <= peo; i++)
			cout << ans[i] << '\n';
		
	}

	return 0;
}