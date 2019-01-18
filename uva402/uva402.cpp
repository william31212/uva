#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva402"
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

	bool person[100];
	int card;

	int qq = 1;
	int n,x;
	while(scanf("%d %d",&n,&x) != EOF)
	{

		memset(person,1,sizeof(person));
		int die = 0;

		for (int j = 0; j < 20; ++j)
		{

			scanf("%d ",&card);
			if (die == n - x)
			{
				continue;
			}

			int cnt = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (person[i])
				{
					cnt++;
				}

				if (cnt == card)
				{
					die++;
					person[i] = 0;
					cnt = 0;
					if( die == n-x )
						break;
				}
			}
		}

		bool flag = 0;
		printf("Selection #%d\n",qq++);
		for (int i = 1; i <= n; ++i)
		{
			if (!flag && person[i])
			{
				printf("%d",i);
				flag = 1;
			}
			else if(person[i])
			{
				printf(" %d",i);
			}
		}
		printf("\n\n");

}



	return 0;
}