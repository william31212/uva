#include <bits/stdc++.h>

using namespace std;

int times = 0;
int num = 0;
int length[25];
bool used[25];

bool check(int ok,int sum,int start,int edge_len,bool used[])
{
	if (ok == 3)
	{
		return true;
	}
	if (sum == edge_len)
	{
		check((ok + 1),0,0,edge_len,used);
	}
	else
	{
		for (int i = start; i < num; ++i)
		{
			if (!used[i] && sum + length[i] <= edge_len)
			{
				used[i] = true;
				if (check(ok,sum+length[i],i+1,edge_len,used))
				{
					return true;
				}
				else
				{
					used[i] = false;
				}
			}
		}
	}
	return false;
}



int main()
{
	#ifdef DBG
	freopen("uva10364.in","r",stdin);
	freopen("uva10364.out","w",stdout);
	#endif


	scanf("%d",&times);
	while(times--)
	{
		int sum = 0;
		int Max = 0;
		memset(used,0,sizeof(used));
		memset(length,0,sizeof(length));


		scanf("%d",&num);
		for (int i = 0; i < num; ++i)
		{
			scanf("%d",&length[i]);
			Max = max(length[i],Max);
			sum += length[i];
		}

		if ( sum/4 < Max || sum % 4 != 0)
		{
			printf("no\n");
			continue;
		}
		// printf("%d %d\n",Max,sum);

		sort(length,length+num,greater<int>());//big to small

		if(!!check(0,sum,0,sum/4,used))
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	

	}
	
	return 0;

}