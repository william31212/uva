#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva10570"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int num;
	int arr[1005];
	int arr2[1005];
	int check[1005];

	while(~scanf("%d",&num) && num)
	{
		//scanf
		int tmp = 0;
		for (int i = 0; i < num; ++i)
		{
			scanf("%d",&tmp);
			arr[i] = tmp - 1;
		}
		for (int i = num; i < num * 2; ++i)
		{
			arr[i] = arr[i - num];
		}

		//往右看
		int small = INT_MAX;
		for (int j = 0; j < num; ++j)//move
		{
			int cnt = 0;

			//build check
			for (int k = j; k < num + j; ++k)
			{
				check[ arr[k] ] = k - j;
			}
			//cut the range
			for (int h = 0; h < num; ++h)
			{
				arr2[h] = arr[h+j];
			}

			//run the index
			for (int i = 0; i < num; ++i)
			{
				if (arr2[i] != i)
				{
					int tmp = arr2[i];
					swap(arr2[check[i]],arr2[i]);
					swap(check[tmp],check[i]);
					cnt++;
				}
			}
						
			small = min(small,cnt);
		}

		//準備往左看
		reverse(arr,arr+num*2);

		//往左看
		for (int j = 0; j < num; ++j)//move
		{
			int cnt = 0;

			//build check
			for (int k = j; k < num+j; ++k)
			{
				check[ arr[k] ] = k - j;
			}

			//cut the range
			for (int h = 0; h < num; ++h)
			{
				arr2[h] = arr[h+j];
			}

			//run the index
			for (int i = 0; i < num; ++i)
			{
				if (arr2[i] != i)
				{
					int tmp = arr2[i];
					swap(arr2[check[i]],arr2[i]);
					swap(check[tmp],check[i]);
					cnt++;
				}
			}
					
			small = min(small,cnt);
		}
	
		printf("%d\n", small);
	}

	return 0;
}