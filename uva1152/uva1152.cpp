#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1152"
#define ismysize 10000007
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

vector <int> vec[ismysize];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	

	int arr1[5000];
	int arr2[5000];
	int arr3[5000];
	int arr4[5000];
	int times;
	int size;
	bool flag = 0;

	cin >> times;

	while(times--)
	{
		
		memset(arr1,0,sizeof(arr1));
		memset(arr2,0,sizeof(arr2));
		memset(arr3,0,sizeof(arr3));
		memset(arr4,0,sizeof(arr4));
		cin >> size;

		for (int i = 0; i < size; ++i)
		{
			cin >> arr1[i] >> arr2[i] >> arr3[i] >> arr4[i];
		}

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				int tmp = abs(arr1[i] + arr2[j]) % ismysize;
				vec[tmp].push_back(arr1[i] + arr2[j]);
			}
		}

		int cnt = 0;

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				int tmp2 = (arr3[i] + arr4[j]) * -1;

				for (int k = 0; k < vec[abs(tmp2) % ismysize].size(); ++k)
				{
					if(vec[abs(tmp2) % ismysize][k] == tmp2)
					{
						cnt++;
					}
				}
			}
		}
		if (!flag)
		{
			printf("%d\n",cnt);
			flag = 1;
		}
		else
			printf("\n%d\n",cnt);

		for (int i = 0; i < ismysize; ++i)
		{
			vec[i].clear();
		}
		
	}

	return 0;
}