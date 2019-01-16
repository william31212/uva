#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva524"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int size = 0;
int ans[16] = {0};
bool visit[17] = {0};
int k = 0;

bool isprime(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

void back_track(int fuck,int n)
{

	if (n == size -1  && isprime(fuck + 1))
	{
		for (int i = 0; i < size; ++i)
		{
			if (i == size - 1)
				printf("%d\n",ans[i]);
			else
				printf("%d ",ans[i]);
		}

		k++;
		return;
	}
	else
	{

		for (int i = 1; i <= size; ++i)
		{
			ans[0] = 1;
			visit[1] = 1;
			if (isprime(fuck + i) && !visit[i])
			{
				ans[n+1] = i;
				visit[i] = 1;
				// printf("%d\n",fuck );
				back_track(i,n+1);

				visit[i] = 0;
				ans[n+1] = 0;
			}
		}
	}


}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	size = 6;

	int num = 0;
	int casefuck = 1;
	while(~scanf("%d",&num) && num)
	{
		if (casefuck != 1)
			printf("\n");
		printf("Case %d:\n", casefuck++);

		size = num;
		ans[16] = {0};
		visit[17] = {0};
		k = 0;
		back_track(1,0);
	}
	return 0;
}