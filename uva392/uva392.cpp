#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva392"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int arr[10];

	while(scanf("%d",&arr[0]) != EOF)
	{
		
		for (int i = 1; i < 9; ++i)
		{
			scanf("%d",&arr[i]);
		}

		bool flag = 0;
		if (!arr[0] && !arr[1] && !arr[2] && !arr[3] && !arr[4] && !arr[5] && !arr[6] && !arr[7] && !arr[8])
		{
			printf("0\n");
			continue;
		}
		for (int i = 0; i < 9; ++i)
		{
			if (arr[i])
			{
				if (!flag)
				{
					if (arr[i] < 0)
					{
						printf("-");
					}
					flag = 1;
				}
				else
				{
					if (arr[i] < 0)
					{
						printf(" - ");
					}
					else
					{
						printf(" + ");
					}
				}

				//number
				if (abs(arr[i]) != 1 && i < 8)
				{
					printf("%d", abs(arr[i]));
				}
				if (i == 8)
				{
					printf("%d", abs(arr[i]));
				}
				if (i < 8)
				{
					printf("x");
					if (i < 7)
					{
						printf("^%d",8-i);
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}