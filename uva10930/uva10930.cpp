#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10930"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 100000
int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t,kase=1;
	int dp[MAXN];
	vector<int>vec;

	while(cin >> t)
	{
		memset(dp,0,sizeof(dp));

		for(int i=0,n;i<t;i++)
			cin >> n,vec.PB(n);
		//check Continuation
		bool flag=0;
		for(int i=1;i<t;i++)
		{
			if(vec[i-1] > vec[i])
				flag=1;
		}

		for(int i=0;i<t;i++)
		{
			if(dp[vec[i]]){
				flag=1;
				break;
			}
			for(int j=30000;j>=vec[i];j--){
				if(dp[j-vec[i]]){
					dp[j]=1;
				}
			}
			dp[vec[i]]=1;
		}

		printf("Case #%d:", kase++);
		if (!flag)
		{
			for (auto i : vec)
				printf(" %d", i);
			printf("\n");
			printf("This is an A-sequence.\n");
		}
		else
		{
			for (auto i : vec)
				printf(" %d", i);
			printf("\n");
			printf("This is not an A-sequence.\n");
		}

		vec.clear();
	}
	return 0;
}