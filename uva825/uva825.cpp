#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva825"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	bool flag=0;
	scanf("%d",&times);
	

	while(times--)
	{
		int x, y;
		vector<int> vec[10000];
		scanf("%d %d\n",&x,&y);
		int dp[x+5][y+5];

		string str;
		stringstream ss;
		int q;

		//The Prohibit region
		for(int i = 1; i <= x; i++)
		{
			getline(cin, str);
			ss.clear();
			ss << str;
			ss >> q;

			while (true)
			{
				ss >> q;
				if (ss.fail())
				{
					break;
				}
				else
				{
					int tmp;
					tmp = q;
					vec[i].PB(tmp);
				}
			}
		}
		memset(dp,0,sizeof(dp));

		//dp 
		for(int i = 1; i <= x; i++)
		{
			for(int j = 1; j <= y; j++)
			{
				if(i == 1 && j == 1)
					dp[i][j] = 1;

				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
				for(auto k : vec[i])
				{
					if(k == j)
					{
						dp[i][j] = 0;
					}
				}
			}
		}
		if(!flag)
			printf("%d\n",dp[x][y]), flag=1;
		else
			printf("\n%d\n",dp[x][y]);		
	}

	return 0;
}