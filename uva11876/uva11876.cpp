#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11876"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
using LL = long long;

LL table[100005];


int nod(int num)
{
	if (num == 1)
	{
		return 1;
	}
	else
	{
		int cnt = 2;
		for(int i = 2; i <= sqrt(num); i++)
		{
			if (i == sqrt(num) && num % i == 0)
				cnt += 1;
			else if (num % i == 0)
			{
				cnt += 2;
			}
		}
		return cnt;
	}
}



int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	memset(table,0,sizeof(table));

	int L,R;

	table[0] = 1;
	for (int i = 1; i < 100005; ++i)
	{
		table[i] = table[i-1] + nod(table[i-1]);
	}

	// for (int i = 0; i < 100005; ++i)
	// {
	// 	cout << table[i] << '\n';
	// }

	int times;
	scanf("%d\n",&times);

	int cases = 1;
	while(times--)
	{
		scanf("%d %d",&L,&R);
		cout << "Case " << cases++ << ": " << upper_bound(table,table+100005,R) - lower_bound(table,table+100005,L) << '\n';
		// printf("%d %d\n",L,R);
	}



	return 0;
}