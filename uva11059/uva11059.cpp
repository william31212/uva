#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11059"
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

	int times;
	int arr[20];
	int cases = 1;

	while(~scanf("%d\n",&times))
	{
		for(int i = 0; i < times; i++)
			scanf("%d",&arr[i]);

		LL maxx = 0;
		for (int i = 0; i < times; i++)
		{
			
			LL tmp = 1;
			for(int j = i; j < times; j++)
			{
				tmp *= arr[j];
				if (maxx < tmp)
					maxx = tmp;
			}
		}

		printf("Case #%d: The maximum product is %lld.\n\n", cases++, maxx);
	}
	return 0;
}