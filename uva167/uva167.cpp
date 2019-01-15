#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva167"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int graph[8][1000];
int rig[16] = {0};
int lef[16] = {0};
int row[8] = {0};
int ans[8] = {0};

int k = 0;
void eight_queen(int n)
{
	if (n == 8)
	{
		for (int i = 0; i < 8; ++i)
		{
			graph[i][k] = ans[i];
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

			if(!row[i] && !rig[r] && !lef[l])
			{
				ans[n] = i;
				row[i] = 1;
				rig[r] = 1;
				lef[l] = 1;
				eight_queen(n+1);
				ans[n] = 0;
				row[i] = 0;
				rig[r] = 0;
				lef[l] = 0;
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
	int arr[8][8];
	scanf("%d",&times);
	while(times--)
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				scanf("%d ",&arr[i][j]);
			}
		}

		int fuckbig = 0;

		for (int i = 0; i < k; ++i)
		{
			int tmp = 0;
			for (int j = 0; j < 8; ++j)
			{
				tmp += arr[graph[j][i]][j];
			}
			fuckbig = max(fuckbig,tmp);
		}

		printf("%5d\n",fuckbig);

	}

	return 0;
}