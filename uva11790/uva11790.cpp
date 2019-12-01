#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11790"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 1000000
struct node
{
	int h;
	int w;
} vec[MAXN];

int pre[MAXN];
int L[MAXN];
int L2[MAXN];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t, tmp, len, kase = 0;

	cin >> t;

	while(t--)
	{
		cin >> len;

		memset(vec, 0, sizeof(vec));
		memset(L,0,sizeof(L));
		memset(L2,0,sizeof(L2));

		for (int i = 0; i < len; i++)
			cin >> vec[i].h;

		for (int i = 0; i < len; i++)
			cin >> vec[i].w;

		for (int i = 0; i < len; i++)
		{
			L[i] = vec[i].w;
			L2[i] = vec[i].w;
		}

		int ans_lis = INT_MIN;
		int ans_lds = INT_MIN;

		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (vec[i].h < vec[j].h)
				{
					L[j] = max(L[i] + vec[j].w, L[j]);
				}
				if (vec[i].h > vec[j].h)
				{
					L2[j] = max(L2[i] + vec[j].w, L2[j]);
				}
			}
			if(L[i] > ans_lis)
				ans_lis = L[i];
			if (L2[i] > ans_lds)
				ans_lds = L2[i];
		}

		if (ans_lds <= ans_lis)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++kase, ans_lis, ans_lds);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++kase, ans_lds, ans_lis);
	}

	return 0;
}