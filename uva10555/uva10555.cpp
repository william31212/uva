#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10555"
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

	string str;
	while (getline(cin, str))
	{
		string num;
		int total_num;
		if (str.size() == 1)
			break;
		else
		{
			for (int i = 2; str[i] != '.'; i++)
				num += str[i];
			total_num = stoi(num);
		}

		int MAX_MOTHER = INT_MAX;
		int MAX_CHILD = INT_MAX;

		for (int i = num.size() - 1; i >= 0; i--)
		{
			//枚舉循環
			string tmp, mo;
			for (int j = i; j < num.size(); j++)
			{
				mo += '9';
			}

			for (int j = 0; j < i; j++)
			{
				tmp += num[j];
				mo += '0';
			}

			if (tmp.size() == 0)
				tmp = '0';

			int tmp_num = stoi(tmp);
			int mother = stoi(mo);
			int child = total_num - tmp_num;

			int isgcd = __gcd(mother, child);
			if (isgcd > 1)
			{
				mother /= isgcd;
				child /= isgcd;
			}

			if (MAX_MOTHER > mother)
			{
				MAX_CHILD = child;
				MAX_MOTHER = mother;
			}
		}
		printf("%d/%d\n", MAX_CHILD, MAX_MOTHER);
	}
	return 0;
}