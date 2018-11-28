#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "A"
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

	int coin[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
	long long money[30005];
	double num;
	memset(money,0,sizeof(money));

	for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 30005; ++j)
			{
				if (j < 5)
				{
					money[j] = 1;
				}
				if (j >= coin[i])
				{
					money[j] += money[j-coin[i]];
				}
			}
		}

	while(scanf("%lf",&num) && num)
	{
		if (num == 0.00)
		{
			break;
		}
		printf("%6.2lf%17lld\n",num,money[(int)round(num*100)]);
	}
	return 0;
}