#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva10285"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)


// 相當奇怪的一題，答案錯AC,答案對RE
// 答案完全是錯的，僅供參考
int area[105][105];
int i_max,j_max;
int max_length = 0;
int a = 0,b = 0,c = 0,d = 0;


int walk(int i,int j,int length)
{

	if (i - 1 < i_max && i - 1 >= 0)//up
	{
		if (area[i][j] > area[i-1][j])
		{
			a = 1;
			walk(i-1,j,length+1);
			a = 0;
		}

	}

	if (i + 1 < i_max && i + 1 >= 0)//down
	{
		if (area[i][j] > area[i+1][j])
		{
			b = 1;
			walk(i+1,j,length+1);
			b = 0;
		}

	}

	if (j - 1 < j_max && j - 1 >= 0 )//left
	{
		if (area[i][j] > area[i][j-1])
		{
			c = 1;
			walk(i,j-1,length+1);
			c = 0;
		}
	}


	if (j + 1 < j_max && j + 1 >= 0 )//right
	{
		if (area[i][j] > area[i][j+1])
		{
			d = 1;
			walk(i,j+1,length+1);
			d = 0;
		}

	}
 	// printf("%d %d %d %d\n",a,b,c,d);

	if (a || b || c || d)//已到盡頭
	{
		max_length = max(max_length,length);
		return max_length;
	}


}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);

	char name[100];

	while(times--)
	{
		memset(area,0,sizeof(area));
		scanf("%s",name);
		scanf("%d",&i_max);
		scanf("%d",&j_max);
		int ans = 0;
		max_length = 0;
		a = b = c = d = 0;

		for (int i = 0; i < i_max; ++i)
		{
			for (int j = 0; j < j_max; ++j)
			{
				scanf("%d",&area[i][j]);
			}
		}

		for (int i = 0; i < i_max; ++i)
		{
			for (int j = 0; j < j_max; ++j)
			{
				// printf("%d\n",walk(i,j,1));
				ans = max(ans , walk(i,j,1));

			}
		}
		if (ans == 0)
		{
			ans = 1;
		}
		printf("%s: %d\n",name,ans);

	}
	return 0;
}