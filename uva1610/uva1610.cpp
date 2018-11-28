#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "B"
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

	string str[1005];
	string str1,str2;
	int num;
	while(scanf("%d",&num) && num)
	{
		for (int i = 0; i < num; ++i)
		{
			cin >> str[i];
		}

		sort(str,str+num);

		str1 = str[(num/2)-1];
		str2 = str[num/2];

		

		string ans = "A";

		int x = str1.size();
		int k = 0;

		while(k < x)
		{
			while(ans[k] <= 'Z' && ans < str1)
				ans[k]++;

			if (ans[k] <= 'Z' && ans >= str1 && ans < str2)
			{
				cout << ans << '\n';
				break;
			}
			if (str1[k] != ans[k])
			{
				ans[k]--;
			}
			ans += 'A';
			k++;
		}


	}

	return 0;
}