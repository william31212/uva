#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1234"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define E 200000

int point,len;
int times;
int ds[E];


struct edge
{
	int from,to,dis;
	bool operator < (const edge &rhs) const
	{ 
		return dis > rhs.dis; 
	}

};

vector <edge> vec;


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);

	while(times--)
	{
		int from,to,dis;
		int point,len;

		scanf("%d %d",&point,&len);

		for (int i = 0; i <= point; ++i)
		{
			ds[i] = i;
		}

		for (int i = 0; i < len; ++i)
		{
			scanf("%d %d %d",&from,&to,&dis);
			vec.push_back((edge){from,to,dis});
		}

		sort(&vec[0],&vec[len]);


		int ans = 0;
		for (int i = 0; i < len; ++i)
		{
			int tmp = vec[i].from;
			int tmp2 = vec[i].to;
			while(ds[tmp] != tmp)
			{
				tmp = ds[tmp];
			}
			while(ds[tmp2] != tmp2)
			{
				tmp2 = ds[tmp2];
			}

			if (tmp == tmp2)
			{
				ans += vec[i].dis;
			}
			else
			{
				ds[tmp2] = tmp;
			}
		}
		vec.clear();
		printf("%d\n",ans );

	}

	return 0;
}