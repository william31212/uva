#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva231"
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

	int num,cas=1,tmp;
	vector <int> vec;
	vector <int> dp;
	bool flag = 0;

	while(cin >> num)
	{
		if(num == -1)
		{
			reverse(vec.begin(),vec.end());
			//塞個-1進去最後再扣掉
			dp.PB(vec[0]);

			for (int i = 1; i < vec.size(); i++)
			{
				if (vec[i] >= dp.back())
					dp.PB(vec[i]);
				else
				{
					*upper_bound(dp.begin(), dp.end(), vec[i]) = vec[i];
				}
			}

			if (!flag)
			{
				printf("Test #%d:\n  maximum possible interceptions: %d\n", cas++, dp.size());
				flag = 1;
			}
			else
				printf("\nTest #%d:\n  maximum possible interceptions: %d\n", cas++, dp.size());

			vec.clear();
			dp.clear();

			cin >> tmp;
			if (tmp == -1)
				break;
			else
			{
				vec.push_back(tmp);
			}
			
		}
		else
		{
			vec.PB(num);
		}
		
		
	}

	return 0;
}