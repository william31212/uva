#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1594"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define MAXN 100

int t, arr[MAXN];

bool check(int len)
{
	for(int i = 0; i < len; i++)
		if(arr[i])
			return false;
	return true;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	cin >> t;
	while(t--)
	{
		int len;
		cin >> len;
		memset(arr,0,sizeof(arr));
		for(int i = 0; i < len; i++)
			cin >> arr[i];
		
		int cnt = 0;
		bool flag = 0;
	
		while(cnt <= 1000)
		{
			if (check(len))
			{
				printf("ZERO\n"), flag = 1;
				break;
			}
			int tmp = arr[0];
			for(int i = 0; i < len; i++)
			{
				if(i == len-1)
					arr[i] = abs(arr[i] - tmp);
				else
					arr[i] = abs(arr[i+1] - arr[i]);
			}
			cnt++;
		}
		if(!flag)
			printf("LOOP\n");
	}
	return 0;
}