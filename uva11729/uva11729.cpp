#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11729"
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

	int times,cases = 1;
	
	while(scanf("%d",&times) && times)
	{
		int B,J;
		vector<pair<int, int>> vec;
		for(int k = 0; k < times; k++)
		{
			scanf("%d %d", &B, &J);
			vec.push_back(make_pair(J, B));
		}
		sort(vec.begin(),vec.end());
		int ans = 0,tmp = 0;
		for(int i = vec.size()-1; i >= 0; i--)
		{
			tmp += vec[i].S;
			ans = max((tmp + vec[i].F) ,ans);
		}
		printf("Case %d: %d\n",cases++,ans);
	}

	return 0;
}