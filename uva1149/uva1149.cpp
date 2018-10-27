#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1149"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	USE_CPPIO();
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif


	int times,num,len;
	cin >> times;

	while(times--)
	{
		cin >> num;
		int arr[num];
		memset(arr,0,sizeof(arr));
		cin >> len;


		for (int i = 0; i < num; ++i)
		{
			cin >> arr[i];
		}
		sort(arr,arr+num);

		int ans = 0;
		int k = 0;

		for (int i = num - 1; i >= 0; --i)
		{
			if (i < k)
			{
				break;
			}
			if (arr[i] == len)
			{
				ans++;
				continue;
			}
			if (arr[i] + arr[k] <= len)
			{
				k++;
				ans++;
				continue;
			}
			else
			{
				ans++;
			}
		}

		cout << ans << '\n';
		if (times >= 1)
		{
			cout << '\n';
		}
	}
	return 0;
}