#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11057"
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

	int n;
	while(cin >> n)
	{
		int check;
		vector <int> vec;
		for(int i = 0, tmp; i < n; i++)
			cin >> tmp, vec.PB(tmp);
		cin >> check;
		sort(vec.begin(),vec.end());

		int diff = INT_MAX;
		int ans0,ans1;
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
			{
				if(vec[i] + vec[j] == check && vec[j] - vec[i] < diff)
				{
					ans0 = vec[i];
					ans1 = vec[j];
				}
			}
		printf("Peter should buy books whose prices are %d and %d.\n\n", ans0, ans1);
	}
	return 0;
}