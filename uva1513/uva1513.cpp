#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1513"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define lowbit(N) (N & -N)

int pos[100005];
int bit[200005];//紀錄下面還有多少個

void add(int x,int v)
{
	while(x < 200005)
	{
		bit[x] += v;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
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
		int movie,req;
		scanf("%d %d",&movie,&req);

		memset(pos,0,sizeof(pos));
		memset(bit,0,sizeof(bit));

		for (int i = 1; i <= movie; ++i)
		{
			pos[i] = movie - i + 1;
			add(pos[i],1);
			printf("\n");
		}


		int req_num;
		int n = movie;
		for (int i = 1; i <= req; ++i)
		{
			cin >> req_num;

			if (i == req)
			{
				printf("%d\n",movie - sum(pos[req_num]));
			}
			else
			{
				printf("%d ",movie - sum(pos[req_num]));
			}

			add(pos[req_num],-1);
			pos[req_num] = ++n;
			add(pos[req_num],1);
		}


	}
	return 0;
}