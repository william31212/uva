#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11136"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define LL long long

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t;

	while (~scanf("%d", &t) && t)
	{
		LL p;
		LL ans = 0;
		multiset<int> ms;
		for(int i = 0; i < t; i++)
		{
			cin >> p;
			for(int j = 0; j < p; j++)
			{
				int tmp;
				cin >> tmp;
				ms.insert(tmp);
			}

			auto it = ms.end();
			it--;
			ans += *it - *ms.begin();
			ms.erase(ms.begin());
			ms.erase(it);
			
		}
		printf("%lld\n",ans);
	}

	return 0;
}