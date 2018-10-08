#include <bits/stdc++.h>

using namespace std;

long long table[100000];
int digit[18];
int rec_digit[17];

void tablee()
{	

	memset(table,0,sizeof(table));
	memset(digit,-1,sizeof(digit));
	int cnt = 1,i = 1,j = 1,first = 0;
	int tmp = 0;
	while(cnt < 100000)
	{
		i = 0;
		digit[i] += 1;

		while(digit[i] == 2)
		{
			digit[i] = 0;
			digit[i+1]++;
			i++;
		}

		j = 17;
		while(digit[j] < 0)
		{
			j--;
		}

		//record position start
		if (!first)
		{
			tmp = j + 2;
			first = 1;
		}
		
		if (tmp == j + 2)
		{
			rec_digit[j + 2] = cnt;
		}
		else
		{
			tmp = j + 2;
		}
		//record position end

		//binary chage 0->1 && 1->2
		while(j >= 0)
		{
			table[cnt] = table[cnt] * 10;//*10之後讓新同學進來

			if( digit[j] == 1 )
				table[cnt] = table[cnt] + 2;
			else if(digit[j] == 0)
				table[cnt] = table[cnt] + 1;
			j--;
		}
		//binary chage end

		//配合題目尾數2
		table[cnt] = table[cnt] * 10;
		table[cnt] = table[cnt] + 2;

		cnt++;
	}
}
	
	



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12406.in","r",stdin);
	freopen("uva12406.out","w",stdout);
	#endif

	tablee();

	int times;
	int p,q;
	int cas = 1;

	scanf("%d",&times);


	while(times--)
	{
		
		scanf("%d %d",&p,&q);
		long long qq= pow(2.0,q);
		if (p == 1)
		{
			if (q > 1)
			{
				printf("Case %d: impossible\n",cas++);
			}
			else
			{
				printf("Case %d: 2\n",cas++);
			}
		}
		else
		{
			int left = rec_digit[p-1] + 1;
			int right = rec_digit[p];
			long long check = 0;
			bool nothing = true;

			// printf("%d %d\n", left,right);
			printf("Case %d:",cas++);
			for (int i = left; i <= right; ++i)
			{
				if (table[i] % qq == 0)
				{
					nothing = false;
					check = table[i];
					printf(" %lld", table[i]);
					break;
				}
			}
			for (int i = right; i >= left ; --i)
			{
				if (check == table[i])
				{
					break;
				}
				else
				{
					if (table[i] % qq == 0)
					{
						printf(" %lld", table[i]);
						break;
					}
				}
			}

			if (nothing)
			{
				printf(" impossible\n");
			}
			else
			{
				printf("\n");
			}
		}

	}


	return 0;
}
	
