#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva1619"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

typedef pair<int, int> P;
typedef long long LL;

#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define maxn 100005




int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int size;

	LL sum[maxn];
	int arr[maxn];
	int l[maxn],r[maxn];

	bool flag = 0;
	while(scanf("%d",&size) != EOF)
	{

		memset(sum,0,sizeof(sum));
		memset(arr,-1,sizeof(arr));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		sum[0] = 0;
		for (int i = 1; i <= size; ++i)
		{
			scanf("%d",&arr[i]);
			sum[i] = sum[i-1] + arr[i];
			l[i] = i;
			r[i] = i;
		}

		for (int i = 1; i <= size; ++i)
		{
			while(arr[l[i] - 1] >= arr[i])//別人比較大填別人，自己比較大就不用動
			{
				l[i] = l[l[i] - 1];
			}
		}

		for (int i = size; i >= 1; --i)
		{
			while(arr[r[i] + 1] >= arr[i])
			{
				r[i] = r[r[i] + 1];
			}
		}


		int ll = 1,rr = 1;
		LL tmp = 0;
		LL maxx = 0;
		for (int i = 1; i <= size; ++i)
		{
			tmp = arr[i] * (sum[r[i]] - sum[l[i] - 1]);
			// printf("%lld\n",tmp);
			// cout << "max: " << maxx << endl;
			if (tmp > maxx)//|| (tmp == maxx && rr - ll > r[i] - l[i])
			{
				maxx = tmp; 
				ll = l[i];
				rr = r[i];
			}
		}

		if (!flag)
		{
			printf("%lld\n",maxx);
			printf("%d %d\n",ll,rr);
			flag = 1;
		}
		else
		{
			putchar('\n');
			printf("%lld\n",maxx);
			printf("%d %d\n",ll,rr);		
		}
	}
	return 0;
}