#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "uva1442"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 1000005

int down[MAXN];
int up[MAXN];
int lef[MAXN];
int rig[MAXN];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	

	int t,len;
	cin >> t;

	while(t--)
	{
		memset(down, 0, sizeof(down));
		memset(up, 0, sizeof(up));
		memset(lef, 0, sizeof(lef));
		memset(rig, 0, sizeof(rig));
		cin >> len;
		for(int i = 1; i <= len; i++)
			cin >> down[i];
		for(int j = 1; j <= len; j++)
			cin >> up[j];

		
		int tmp = lef[1] = up[1];

		//天花板高油過不去
		//地板高
		for(int i = 1; i < len; i++)
		{
			if(tmp >= up[i+1])
				tmp = up[i+1];

			if(tmp <= down[i+1])
				tmp = down[i+1];
			
			lef[i+1] = tmp;
		}


		tmp = rig[len] = up[len];

		for (int i = len; i >= 2; i--)
		{
			if (tmp >= up[i-1])
				tmp = up[i-1];

			if (tmp <= down[i-1])
				tmp = down[i-1];

			rig[i-1] = tmp;
		}


		int ans = 0;
		for(int i = 1; i <= len; i++)
			ans += min(lef[i],rig[i])- down[i];
		
		printf("%d\n",ans);
	}

	return 0;
}