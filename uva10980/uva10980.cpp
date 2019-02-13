#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10980"
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


	int mnt;
	int val[100];
	int wei[100];
	int one = 0,two = 0;
	int dp[205];
	int q;
	int cases = 0;
	string str;

	while(~scanf("%d.%d %d\n",&one,&two,&mnt))
	{
		memset(val,0,sizeof(val));
		memset(wei,0,sizeof(wei));
		memset(dp,0,sizeof(dp));

		dp[0] = 0;

		for (int i = 1; i < 205; ++i)
		{
			dp[i] = INF;
		}

		//以原價買一
		int origin = one * 100 + two;

		for (int i = 1; i < 205 ; ++i)
		{
			dp[i] = min(dp[i-1] + origin , dp[i]);
		}


		for (int i = 0; i < mnt; ++i)
		{
			scanf("%d %d.%d\n",&wei[i],&one,&two);
			val[i] = one * 100 + two;
		}

		for (int i = 0; i < mnt; ++i)
		{
			for (int j = wei[i]; j <= 200; ++j)
			{
				dp[j] = min(dp[j - wei[i]] + val[i] , dp[j]);
			}
		}

		for(int j = 200; j >= 0; j--)
            dp[j] = min(dp[j], dp[j+1]);



        //output
		printf("Case %d:\n", ++cases);

		string str;
		stringstream ss;
		int q;

		getline(cin, str);
		ss.clear();
		ss << str;

		while(true)
		{
			ss >> q;
			if(ss.fail())
				break;
			 printf("Buy %d for $%d.%02d\n", q, dp[q]/100, dp[q]%100);
		}

	}

	return 0;
}