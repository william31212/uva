#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva12086"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define lowbit(k) (k&(-k))
#define MAXN 300000

int table[MAXN+5];
int BIT[MAXN+5];

void build(int t)
{
	for (int i = 1; i <= t; i++)
	{
		for (int j = i; j <= t; j += lowbit(j))
		{
			BIT[j] += table[i];
		}
	}
}

int total(int a)
{
	int ans = 0;
	for (int j = a; j >= 1; j -= lowbit(j))
	{
		ans += BIT[j];
	}
	return ans;
}

void print_BIT(int t)
{
	for (int i = 1; i <= t; i++)
	{
		printf("%d ",BIT[i]);
	}
	printf("\n");
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int t,kase=1,flag=0;
	string str;

	while(cin >> t && t)
	{
		
		memset(table,0,sizeof(table));
		memset(BIT,0,sizeof(BIT));
		for(int i = 1, tmp; i <= t && cin >> tmp; i++)
			table[i] = tmp;

		build(t);
		if(!flag)
			printf("Case %d:\n", kase++),flag=1;
		else
			printf("\nCase %d:\n", kase++);
		while(cin >> str && str != "END")
		{
			
			int a, b;
			if(str == "M")
			{		
				cin >> a >> b;
				printf("%d\n",total(b) - total(a-1));
			}
			else if(str == "S")
			{
				cin >> a >> b;
				int delta = b - table[a];
				table[a] = b;
				for(int i = a; i <= t; i+=lowbit(i))
					BIT[i] += delta;	
			}
		}
	}
		
	return 0;
}