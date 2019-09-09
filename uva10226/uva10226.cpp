#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10226"
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

	int t;
	scanf("%d\n\n",&t);
	
	while(t--)
	{
		string str;
		map<string, int> m;
		int cnt = 0;
		while(getline(cin,str))
		{
			if(!str.size())
				break;
			if(!m.count(str))
			{
				m.insert(MP(str,1));
			}
			else
			{
				m[str] += 1;
			}
			cnt++;
		}

		for(auto i : m)
		{
			double ans = (double)i.S / (double)cnt;
			printf("%s %.4lf\n", i.F.c_str(), ans*100);
		}
		if(t == 0)
			break;
		else
			putchar('\n');
	}

	return 0;
}