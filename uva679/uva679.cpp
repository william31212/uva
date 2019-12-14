#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva679"
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

	int t,d,k;
	while(cin >> t)
	{
		if(t < 0)
			break;
		while(t--)
		{
			cin >> d >> k;
			int s = 1 << d-1;

			string tmp = "";

			for(int i = 0; i < d-1; i++)
				tmp += '0';
			int tmp_k = k-1;
			int idx = tmp.size()-1;
			while(tmp_k > 0)
			{
				tmp[idx] = (tmp_k % 2) + '0';
				tmp_k /= 2;
				idx--;
			}
			int offset = 0;
			for(int i = 0; i < tmp.size(); i++)
			{
				if(tmp[i] == '1')
					offset += 1 << i;
			}
			printf("%d\n",s+offset);
		}

	}

	return 0;
}