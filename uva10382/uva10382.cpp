#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva10382"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

typedef pair<double, double> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back


int times,len;
double width;


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cnt = 0;
	while(~scanf("%d %d %lf",&times,&len,&width))
	{
		P node[100000];

		double point,half;
		int realsize = 0;

		for (int i = 0; i < times; ++i)
		{
			scanf("%lf %lf",&point,&half);
			if ((half *half) - (width/2) * (width/2) > 0)
			{
				node[realsize].F = point - sqrt((half *half) - (width/2) * (width/2));
				node[realsize].S = point + sqrt((half *half) - (width/2) * (width/2));
				realsize++;
			}
		}

		sort(node,node+realsize);

		if (node[0].F > 0)
		{
			printf("-1\n");

			continue;
		}

		double Left = 0;
		double Right = 0;
		int ans = 0;

		for (int i = 0; i < realsize ; )
		{	
			if (Right >= len)
			{
				break;
			}
			while(node[i].F <= Left && i < realsize)
			{
				Right = max(Right,node[i].S);
				i++;
			}
			
			if (Right > Left)
			{
				ans++;
				Left = Right;
			}
			else if (Right == Left)
			{
				break;
			}
		
		}

		if (Right < (double)len)
		{
			ans = -1;
		}
		printf("%d\n",ans);

	}

	return 0;
}