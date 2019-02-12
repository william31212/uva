#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva10130"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	USE_CPPIO();
	int times;
	int kind;
	int arr[2][1005];
	cin >> times;

	while(times--)
	{
		memset(arr,0,sizeof(arr));
		cin >> kind;

		for (int i = 0; i < kind; ++i)
		{
			cin >> arr[0][i] >> arr[1][i];
		}

		int people;
		cin >> people;

		int backage[people];
		int upper = 0;

		for (int i = 0; i < people; ++i)
		{
			cin >> backage[i];
			upper = max(upper,backage[i]);
		}

		int ans[2][1005];
		memset(ans,0,sizeof(ans));

		for (int i = 0; i < kind; ++i)
		{
			for (int j = 1; j <= upper; ++j)
			{
				if (j >= arr[1][i])
				{
					ans[1][j] = max( arr[0][i] + ans[0][j-arr[1][i]] , ans[0][j]);
				}
			}

			for (int k = 1; k <= upper; ++k)
			{
				ans[0][k] = ans[1][k];
			}
		}

		int sum = 0;
		for (int i = 0; i < people; ++i)
		{
			sum += ans[1][backage[i]];
		}

		cout << sum << '\n';

	}
	return 0;
}