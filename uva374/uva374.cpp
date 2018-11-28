#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva374"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

long long mi(long long a,long long b,int p)
{
	if (b == 1)
	{
		return a;
	}
	else if(b % 2 != 0)
	{
		long long y = mi(a,b/2,p) % p;
		return (a * y * y) % p;
	}
	else
	{
		long long y = mi(a,b/2,p) % p;
		return (y * y) % p;
	}
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	long long B,P,M;
	
	while(cin >> B >> P >> M)
	{
		if (P == 0)
		{
			cout << 1 % M << '\n';
			continue;
		}
		else
			cout << mi(B,P,M) << '\n';
	}
	return 0;
}