#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva10178"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int dj[100];
int V,E;
char a,b;

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	while(~scanf("%d %d\n",&V,&E))
	{

		for (int i = 0; i < 100; ++i)
		{
			dj[i] = i;
		}

		int ans = 1;
		for (int i = 0; i < E; ++i)
		{
			scanf("%c %c\n",&a,&b);
			int tmp1 = a - 'A';
			int tmp2 = b - 'A';

			while(dj[tmp1] != tmp1)
				tmp1 = dj[tmp1];

			while(dj[tmp2] != tmp2)
				tmp2 = dj[tmp2];

			if (tmp1 == tmp2)//成環多一區
				ans++;
			else
				dj[tmp1] = tmp2;
		}

		printf("%d\n",ans );
	}
	return 0;
}