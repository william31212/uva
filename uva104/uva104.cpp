#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva104"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
 	
	int kind;
	while(cin >> kind)
	{
		double coin[25][25][25];
		int path[25][25][25];
		memset(coin,0,sizeof(coin));
		memset(path,0,sizeof(path));
		for(int i = 1; i <= kind; i++)
		{	
			for(int j = 1; j <= kind; j++)
			{
				if(i == j)
					coin[1][i][j] = 1;
				else
					cin >> coin[1][i][j];
			}
		}

		for(int i = 1; i <= kind; i++)
		{	
			for(int j = 1; j <= kind; j++)
			{
				path[1][i][j] = i;
			}
		}

		
		double tmp = 0;
		for(int change_step = 2; change_step <= kind; change_step++)//做幾步
		{
			for (int i = 1; i <= kind; ++i)
			{
				for (int j = 1; j <= kind; ++j)
				{
					for (int k = 1; k <= kind; ++k)//i -> k -> j
					{
						if (k == j)
						{
							continue;
						}
						tmp = coin[change_step - 1][i][k] * coin[1][k][j];//ex:前一格1->2的狀態，* 想要嘗試的第j個
						if (tmp > coin[change_step][i][j])
						{
							coin[change_step][i][j] = tmp;
							path[change_step][i][j] = k;
						}
					}
					
				}
			}					
		}		



		stack <int> stk;
		bool flag = 0;
		for (int k = 1; k <= kind; k++)
		{
			for (int i = 1; i <= kind; ++i)
			{
				for (int j = 1; j <= kind; ++j)
				{
					if (i == j)
					{
						if (coin[k][i][j] > 1.01)
						{
							for (int road = k ; road >= 1; road--)
							{
								stk.push(path[road][i][j]);
								j = path[road][i][j];
								flag = 1;
							}
							break;
						}
					}
				}
				if (flag)
				{
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}

		if (!flag)
		{
			printf("no arbitrage sequence exists\n");
			continue;
		}

		int ans = stk.top();
		while(!stk.empty())
		{
			printf("%d ", stk.top());
			stk.pop();
		}
		
		printf("%d\n", ans);


	}	
  		

	return 0;
}
