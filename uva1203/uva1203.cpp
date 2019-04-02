#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva1203"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

struct node
{
	int time;
	int period;
	int now;

	bool operator < (const node &rhs) const
	{
		return now > rhs.now || (now == rhs.now && time > rhs.time);
	}
};


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	string str;
	int time;
	int period;
	int num;

	priority_queue <node> pq;

	while(cin >> str)
	{
		if (str[0] == '#')
		{
			cin >> num;

			int cnt = 0;
			while(!pq.empty())
			{
				if (cnt == num)
					break;
				cout << pq.top().time << '\n';
				cnt++;

				// printf("%d %d\n",pq.top().time, pq.top().now);
				pq.push(node{(pq.top().time), (pq.top().period), (pq.top().now + pq.top().period)});
 				pq.pop();
 			}
		}
		else
		{
			cin >> time >> period;
			pq.push(node{time, period, period});
		}

	}


	return 0;
}