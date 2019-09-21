#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva846"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 100000
#define LL long long


LL arr[MAXN];
void build()
{
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	int cnt = 0;
	int add_num = 2;
	for(int i = 2; i < MAXN; i++)
	{
		if(cnt < 2)
			arr[i+1] = arr[i] + add_num,cnt++;
		if(cnt == 2)
			cnt = 0,add_num+=1;
	}
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t;
	cin >> t;

	build();
	while(t--)
	{
		int a,b;
		cin >> a >> b;
		for(int i = 0; i < MAXN; i++)
		{
			if(abs(b-a) <= arr[i])
			{
				printf("%d\n",i);
				break;
			}
		}
	}

	return 0;
}