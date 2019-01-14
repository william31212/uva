#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11401"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define maxn 1000005
#define ULL unsigned long long

ULL dp[maxn];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	memset(dp,0,sizeof(dp));

	for (int i = 0; i < maxn; ++i)
	{
		/*
		find the max edge
		a1 = a1 - d + a1 - 2d + a1 - (n-1)d 
		n * a1 - ((n-1 + 0) * n)*d/2
		n[a1 - n + 1]
		*/
		if (i >= 4)
		{
			ULL a1 = i - 3;
			ULL n = (a1 + 1) / 2;
			dp[i] = dp[i-1] + n * ( a1 - n + 1);
		}
	}

	int num;
	while(scanf("%d",&num) && num)
	{
		if (num < 3)
		{
			break;
		}
		else	
			cout << dp[num] << '\n';
	}

	return 0;
}