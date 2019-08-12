#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10625"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define ULL unsigned long long

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	ULL dp[200][2];
	ULL tmp[200];
	bool indic[200];

	memset(dp , 0, sizeof(dp));
	memset(tmp, 0, sizeof(tmp));
	scanf("%d",&times);

	while(times--)
	{
		int dict;
		scanf("%d",&dict);
		string str[20];
		memset(indic, 0, sizeof(indic));
		for(int i = 0; i < dict; i++)
		{
			cin >> str[i];
			indic[str[i][0]] = 1;
		}
			

		int query;
		scanf("%d",&query);
		string ori;
		char ans;
		int t;
		for(int j = 0; j < query; j++)
		{
			memset(dp, 0, sizeof(dp));
			cin >> ori;
			cin >> ans;
			cin >> t;

			//init
			for(int it = 0; it < ori.size(); it++)
			{
				dp[ori[it]][0] += 1;
			}

			//query
			for(int i = 0; i < t; i++)
			{
				//if GNU no inherit
				for (int kk = 0; kk < 200; kk++)
				{
					if(!indic[kk])
						dp[kk][1] = dp[kk][0];
				}
				
				//G->N->U
				for (int it2 = 0; it2 < dict; it2++)
				{
					memset(tmp, 0, sizeof(tmp));
					char fr = str[it2][0];
					for (int str_it = 3; str_it < str[it2].size(); str_it++)
					{
						tmp[str[it2][str_it]] += 1;
					}

					ULL w_add = dp[fr][0];
					for (int kk = 0; kk < 200; kk++)
					{
						dp[kk][1] += tmp[kk] * w_add;
					}
				}

				for (int kk = 0; kk < 200; kk++)
				{
					dp[kk][0] = dp[kk][1];
					dp[kk][1] = 0;
				}

				
			}
			
			cout << dp[ans][0] << '\n';
			
			
		}
		
		
		
		
	}

	return 0;
}