#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva1620"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 505

int arr[MAXN];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int n;

	cin >> n;

	while(n--)
	{
		int len;
		cin >> len;
		for(int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}

		int cnt = 0;
		for(int i = 0; i < len-1; i++)
			for(int j = i+1; j < len; j++)
			{
				if(arr[j] < arr[i])
					cnt++;
			}

		if(len % 2 && cnt % 2)
			printf("impossible\n");
		else
			printf("possible\n");
	}

	return 0;
}