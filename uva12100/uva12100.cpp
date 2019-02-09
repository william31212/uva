#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva12100"
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
	int n,m;


	scanf("%d",&times);


	while(times--)
	{
		scanf("%d %d",&n,&m);
		priority_queue<int> pq;
		deque<pair<int,int>> dq;
		int order,pos = 0;

		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&order);
			pq.push(order);
			dq.PB(MP(order,pos));
			pos++;
		}

		int ans = 0;

		while(true)
		{
			int top = pq.top();
			pq.pop();
			while(dq.front().F != top)
			{
				int tmpF = dq.front().F;
				int tmpS = dq.front().S;
				dq.pop_front();
				dq.PB(MP(tmpF,tmpS));
			}
			if (dq.front().S == m)
			{
				ans++;
				break;
			}
			else
			{
				dq.pop_front();
				ans++;
			}

		}

		printf("%d\n",ans);

	}
	return 0;
}