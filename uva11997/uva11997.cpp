#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11997"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct node
{
	int val;
	int pos;

	bool operator < (const node &r) const
	{
		return val > r.val;//4 > 3 要return 1，代表要換
	}
};


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int n,len[805],len2[805];


	while(scanf("%d",&n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&len[i]);
		}
		sort(len,len+n);

		for (int k = 1; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				scanf("%d",&len2[i]);
			}
			sort(len2,len2+n);
			//------------------------------
			priority_queue <node> my_heap;

			for (int i = 0; i < n; ++i)
			{
				my_heap.push({len[i] + len2[0] , 0});
			}


			for (int i = 0; i < n; ++i)
			{
				node tmp = my_heap.top();
				my_heap.pop();

				len[i] = tmp.val;

				if (tmp.pos + 1 < n)
				{
					my_heap.push({tmp.val - len2[tmp.pos] + len2[tmp.pos + 1] , tmp.pos + 1});
				}
			}

		}

		for (int i = 0; i < n-1; ++i)
		{
			printf("%d ", len[i]);
		}
		printf("%d\n",len[n-1]);
		


	}

	


	
	return 0;
}