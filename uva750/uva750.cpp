#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva750"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back


int graph[8][1000];
int lef[16];
int rig[16];
int row[8];
int ans[8];

int k = 0;
void eight_queen(int n)
{
	if (n == 8)
	{
		for (int i = 0; i < 8; ++i)
		{
			graph[i][k] = ans[i] + 1;
		}
		k++;
		return;
	}
	else
	{
		for (int i = 0; i < 8; ++i)
		{
			int r = n + i;
			int l = n - i + 7;

			if (!row[i] && ! lef[l] && !rig[r])
			{
				ans[n] = i;
				row[i] = 1;
				lef[l] = 1;
				rig[r] = 1;
				eight_queen(n+1);
				ans[n] = 0;
				row[i] = 0;
				lef[l] = 0;
				rig[r] = 0;
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

	eight_queen(0);

	int times;
	int row,col;
	scanf("%d",&times);


	while(times--)
	{

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n");
		printf("\n");
		scanf("%d %d",&row,&col);

		int fuck = 1;
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (j == col - 1 && graph[j][i] == row)
				{
					printf("%2d     ",fuck++);
					for (int s = 0; s < 8; ++s)
					{
						if (s == 7)
							printf("%d\n",graph[s][i]);
						else if (s == 0)
							printf(" %d ",graph[s][i]);
						else
							printf("%d ",graph[s][i]);
					}

				}

			}

		}
		if (times != 0)
		{
			printf("\n");
		}

	}
	return 0;
}