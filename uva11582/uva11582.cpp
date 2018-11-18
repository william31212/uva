#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11582"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)


int fast_mi(unsigned long long a,unsigned long long b,int p)
{
	if (b == 1)
	{
		return a;
	}
	else if(b % 2 == 0)
	{
		unsigned long long mod_tmp = fast_mi(a,b/2,p) % p;
		return mod_tmp * mod_tmp % p;
	}
	else
	{
		unsigned long long mod_tmp2 = fast_mi(a,b/2,p) % p;
		return (a * mod_tmp2 * mod_tmp2) % p;
	}
}




int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	vector <int> mod[1005];
	for (int n = 2; n <= 1000; ++n)//mod
	{
		for (int i = 0; i <= 10000; ++i)//fib
		{
		
			if (i == 0 || i == 1)
			{
				mod[n].push_back(1);
				continue;
			}
			
			mod[n].push_back( (mod[n][i-1] + mod[n][i-2]) % n );
			mod[n][i] %= n;
			

			if (mod[n][i] == 1 && mod[n][i-1] == 0)
			{
				mod[n].pop_back();
				break;	
			}

		}
		
	}

	int times;
	cin >> times;
	mod[0].push_back(0);
	mod[1].push_back(0);
	unsigned long long a,b,input_n;
	while(times--)
	{
		cin >> a >> b >> input_n;
		if (b == 0)
		{
			cout << 1 % input_n << '\n';
			continue;
		}
		int p = mod[input_n].size();
		
		unsigned long long dee = a % p;
		// cout << dee << " " << b << " " << p  << '\n';
		

		if (fast_mi(dee,b,p) == 0)
		{
			cout << "0" << '\n';
		}
		else
			cout << mod[input_n][fast_mi(dee,b,p) - 1] << '\n';

	}


	return 0;
}