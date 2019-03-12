#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva714"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define maxn 505

typedef long long LL;


bool slash[maxn];
int n,k;
LL arr[maxn];


bool check(LL cut)//是否能用這個數字來切
{
	int cnt = 1;
	int j = 0;
	for (int i = 0; i < n; i = j)
	{
		if(cnt > k)
			return false;

		LL sum = 0;

		for (j = i; j < n; ++j)
		{
			if (arr[j] > cut)
				return false;
			if (sum + arr[j] <= cut)
				sum += arr[j];
			else
				break;

		}
		cnt++;
	}

	return true;

}

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
		scanf("%d %d",&n,&k);
		LL L = 0,R = 0;

		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&arr[i]);
			R += arr[i];
		}
		while(L < R)
		{
			LL mid = (L + R) / 2;
			if (check(mid))
				R = mid;
			else
				L = mid + 1;

			// printf("%lld %lld %lld\n",L,R,mid);
		}

		memset(slash,0,sizeof(slash));
		LL sum = 0;
		int tmp = k;

		for (int i = n-1 ; i >= 0 ; --i)//題目要求若有多組解，後面工人的頁數盡量多一點，所以從最右開始分配
		{
			if (sum + arr[i] > R || i + 1 < tmp)//該劃界線 or 書還有剩但還要分很多
			{
				slash[i] = true;
				sum = arr[i];
				tmp--;
			}
			else
			{
				sum += arr[i];
			}
		}

		for (int i = 0; i < n-1; ++i)
		{
			printf("%lld ",arr[i]);
			if(slash[i])
				printf("/ ");

		}
		printf("%lld\n",arr[n-1]);
	}

	return 0;
}