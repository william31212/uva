#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva455"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)


bool check(string &str, int len)
{
	for (int i = 1; i < str.length()/len ; ++i)//長度二，做四次
	{
		for (int j = i * len ; j <= (i * len) + len - 1 ; ++j)
		{
			if (str[j] != str[j % len])
			{
				return false;
			}
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

	int times;

	cin >> times;

	string str;

	while(times--)
	{
		cin >> str;

		for (int i = 1; i <= str.length(); ++i)
		{
			if ((str.length() % i == 0) && check(str,i))
			{
				cout << i << endl;
				break;
			}
		}
		if (times > 0)
		{
			cout << '\n';
		}
	}

	return 0;
}