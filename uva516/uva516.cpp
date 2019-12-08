#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva516"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 100000

bool isprime[MAXN];
vector<P>prime;
vector<int>vec;


int fast_mi(int a, int b)
{
	if(b == 0)
		return 1; 
	else if(b == 1)
		return a;
	else
	{
		int tmp = fast_mi(a, b / 2);
		if (b & 1) 
			return tmp * tmp * a;
		else
			return tmp * tmp;
	}	
}

void build()
{
	fill(isprime,isprime+MAXN,1);
	for(int i = 2; i < 33000; i++)
	{
		if (isprime[i])
		{
			prime.PB(MP(i,0));
			for (int j = i * i; j < 33000; j += i)
				isprime[j] = 0;
		}
	}
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	string str;
	build();
	
	while(getline(cin,str))
	{
		if(str == "0")
			break;
		vec.clear();
		string tmp;
		for(int i = 0; i < str.size(); i++)
		{
			tmp += str[i];
			if(str[i] == ' ')
			{
				vec.push_back(stoi(tmp));
				tmp = "";
			}
		}
		vec.push_back(stoi(tmp));

		int ans = 1;
		for(int j = 0; j < vec.size(); j+=2)
		{
			ans *= fast_mi(vec[j], vec[j + 1]);
		}
		ans -= 1;
		// cout << ans << '\n';
		
		for(int k=0;k<prime.size();k++)
		{
			if (ans < prime[k].F) 
				break;
			// cout << ans << " " << prime[k].F << '\n';
			while (ans % prime[k].F == 0 && ans >= prime[k].F)
			{
				ans /= prime[k].F;
				prime[k].S += 1;
			}
		}

		bool flag = 0;

		for(int k=prime.size()-1; k>=0; k--)
		{
				if(prime[k].S > 0)
				{
					if (!flag)
						printf("%d %d", prime[k].F, prime[k].S), flag = 1;
					else
						printf(" %d %d", prime[k].F, prime[k].S);
					prime[k].S = 0;
				}
		}
		puts("");

	}


	return 0;
}