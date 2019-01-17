#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10015"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

vector <int> prime;
bool isprime(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return false;
		}

	}
	return true;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	for (int i = 2; i <= 35000; ++i)
	{
		if (isprime(i))
		{
			prime.PB(i);
		}
	}

	int num;
	bool pass[4000];
	while(scanf("%d",&num) && num)
	{
		memset(pass,1,sizeof(pass));
		int prime_count = num - 2;
		int tmp = num;
		int bef = 1;


		for (int j = 0; j <= prime_count ; ++j)
		{
			int cnt = 0;
			int moder = prime[j] % tmp;
			if(moder == 0)
				moder = tmp;

			for (int i = bef; i <= num ; ++i)
			{
				if (pass[i])
				{
					cnt++;
				}
				if (cnt == moder)
				{
					pass[i] = 0;
					tmp -= 1;
					bef = i;
					break;
				}
				if (i == num)
					i = 0;
			}

		}

		for (int i = 1; i <= num; ++i)
		{
			if (pass[i])
			{
				printf("%d\n",i);
				break;
			}
		}
	}

	return 0;
}