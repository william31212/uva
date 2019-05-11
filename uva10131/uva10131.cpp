#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10131"
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
	int idx,wei,iq;
	bool operator < (const node & rhs) const
	{
		return iq > rhs.iq;
	}
};


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int wei,iq,idx=1;
	vector<node> v;
	while(~scanf("%d %d",&wei,&iq))
	{
		v.PB((node){idx++,wei,iq});
	}

	sort(v.begin(),v.end());

	// for(auto i : v)
	// 	cout << i.idx << " " << i.wei << " " << i.iq << '\n';

	int LIS[v.size()+5];
	int prev[v.size()+5];
	for(int i = 0; i < v.size()+5; i++)
		LIS[i] = 1;
	memset(prev,-1,sizeof(prev));

	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < i; ++j)
			if( v[j].wei < v[i].wei)
			{
				if (LIS[j] + 1 > LIS[i])
				{
					LIS[i] = LIS[j] + 1;
					prev[i] = j;
				}
			}

	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	cout << prev[i] << '\n';
	// }

	int n, pos = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (LIS[i] > n)
		{
			n = LIS[i];
			pos = i;
		}
	}

	stack<int>stk;
	for (int i = pos; i != -1 ; i=prev[i])
		stk.push(v[i].idx);

	cout << stk.size() << '\n';
	while(!stk.empty())
	{
		cout << stk.top() << '\n';
		stk.pop();
	}



	return 0;
}