#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva572"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define N 105

int r,c;
int x_n,y_n;
int graph[N][N];

void dfs(int x,int y)
{
	//left
	// printf("%d %d\n",x,y );

	//up
	if(y > 1)
	{
		if (graph[y-1][x] == 0)
		{
			graph[y-1][x] = 1;
			dfs(x,y-1);
		}
	}

	//down
	if(y < y_n)
	{
		if (graph[y+1][x] == 0)
		{
			graph[y+1][x] = 1;
			dfs(x,y+1);
		}
	}

	if(x > 1)
	{
		if (graph[y][x-1] == 0)
		{
			graph[y][x-1] = 1;
			dfs(x-1,y);
		}
	}

	//right
	if(x < x_n)
	{
		if (graph[y][x+1] == 0)
		{
			graph[y][x+1] = 1;
			dfs(x+1,y);
		}
	}


	//right down
	if(x < x_n && y < y_n)
	{
		if (graph[y+1][x+1] == 0)
		{
			graph[y+1][x+1] = 1;
			dfs(x+1,y+1);
		}
	}

	//left up
	if(x > 1 && y > 1)
	{
		if (graph[y-1][x-1] == 0)
		{
			graph[y-1][x-1] = 1;
			dfs(x-1,y-1);
		}
	}

	//left down
	if(x > 1 && y < y_n)
	{
		if (graph[y+1][x-1] == 0)
		{
			graph[y+1][x-1] = 1;
			dfs(x-1,y+1);
		}
	}

	//right up
	if(x < x_n && y > 1)
	{
		if (graph[y-1][x+1] == 0)
		{
			graph[y-1][x+1] = 1;
			dfs(x+1,y-1);
		}
	}


}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif


	while(~scanf("%d %d\n",&r,&c) && r && c)
	{
		memset(graph,0,sizeof(N));

		x_n = c;
		y_n = r;

		char tmp;
		for(int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; ++j)
			{
				scanf("%c",&tmp);
				if (tmp == '@')
					graph[i][j] = 0;
				else
					graph[i][j] = -1;
			}
			getchar();
		}



		int cnt = 0;
		for(int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; ++j)
			{

				// printf("%d %d %d \n",i,j,graph[i][j] );
				if (graph[i][j] == 0)
				{
					cnt++;
					dfs(j,i);
				}

			}
		}

		printf("%d\n",cnt);


	}

	return 0;
}