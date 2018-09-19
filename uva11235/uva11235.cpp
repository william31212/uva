#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int main()
{
	#ifdef DBG
	freopen("uva11235.in","r",stdin);
	freopen("uva11235.out","w",stdout);
	#endif
	
	int len,times;

	while(~scanf("%d %d",&len,&times))
	{
		int arr[MAX];
		int total[MAX];
		int left[MAX];
		int right[MAX];
		int type[MAX];
		
		fill(arr,arr+MAX,0);
		fill(total,total+MAX,0);
		fill(left,left+MAX,0);
		fill(right,right+MAX,0);
		fill(type,type+MAX,0);
		if (!len)
			break;

		for (int i = 0; i < len; ++i)
		{
			scanf("%d",&arr[i]);
		}

		int total_index = 0;
		int pre = 0,next = 0;	
		for (int i = 0; i < len; ++i)
		{
			if (i == 0)
			{
				pre = arr[i];
				total[total_index]++;
				continue;
			}
			else
			{
				next = arr[i];
				if (pre != next)
				{
					pre = next;
					total_index++;
					total[total_index]++;	
				}
				else
				{
					total[total_index]++;
				}
			}
		}


		int cnt = 0;
		for (int i = 0; i < len; ++i)
		{
			if (i == 0)
			{
				pre = arr[i];
				type[0] = 0;
				continue;
			}
			else
			{
				next = arr[i];
				if (pre != next)
				{
					pre = next;
					cnt++;
					type[i] = cnt;

				}
				else
				{
					type[i] = cnt;
				}
			}
		}


		int tmp_left = 0;
		for (int i = 0; i < len; ++i)
		{
			if (i == 0)
			{
				pre = arr[i];
				left[0] = 0;
				continue;
			}
			else
			{
				next = arr[i];
				if (pre != next)
				{
					pre = next;
					tmp_left = i;
					left[i] = tmp_left;
				}
				else
				{
					left[i] = tmp_left; 
				}
			}

		}

		int tmp_right = len-1;
		for (int i = len - 1; i >= 0; --i)
		{
		 	if (i == len - 1)
		 	{
		 		pre = arr[i];
		 		right[len-1] = len-1;
		 		continue;
		 	}
		 	else
		 	{
		 		next = arr[i];
		 		if (pre != next)
		 		{
		 			pre = next;
		 			tmp_right = i;
		 			right[i] = tmp_right;
		 		}
		 		else
		 		{
		 			right[i] = tmp_right;
		 		}
		 	}
		}
			while(times--)
			{
				int l,r;	
				scanf("%d %d",&l,&r);
				l--;
				r--;
				int leftest = l;
				int rightest = r;
				if (type[l] == type[r])
				{
				 	printf("%d\n", r-l+1);
				}
				else
				{
					while(left[r] == left[rightest])
					{
						rightest--;
					}
					while(right[l] == right[leftest])
					{
						leftest++;
					}
					rightest++;
					leftest--;

					int ans_1 = r - rightest + 1; 
					int ans_2 = leftest - l + 1;
					
					int b = type[rightest-1];
					// printf("%d\n",total[type[rightest-1]] );
					int a = type[leftest+1];
					
					if (abs(rightest-leftest) == 1)
					{
						printf("%d\n",max(ans_1,ans_2));
					}
					else
					{
						int ans_tmp;
						for (int i = a; i <= b; ++i)
						{
							if (i == a)
							{
								ans_tmp = max(ans_1,total[i]);
								ans_tmp	= max(ans_2,ans_tmp);
							}
							else
							{
								ans_tmp = max(ans_tmp,total[i]);
							}
						}
						printf("%d\n",ans_tmp);
					}
					
					
				}
			}
	
	}


	return 0;

}