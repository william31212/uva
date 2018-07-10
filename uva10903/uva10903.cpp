#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


int check(char m[]){
	if ( !strcmp( m , "rock" ))
	{
		return 1;
	}
	else if ( !strcmp( m , "scissors" ))
	{
		return 2;
	}
	else if ( !strcmp( m , "paper" ))
	{
		return 3;
	}
}


int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10903.in","r",stdin);
	freopen("uva10903.out","w",stdout);
	#endif
	int n,k;
	int num,num2;
	int m1,m2;
	int game;
	bool flag = 0;
	char str[10];
	char str2[10];
	while(scanf("%d",&n)!=EOF && n)
	{
		if (flag)
		{
			printf("\n");
		}
		
		int winarray[101] = {0};
		int losearray[101] = {0};
		scanf("%d",&k);

		game = k*n*(n-1)/2;
		for (int i = 0; i < game; ++i)
		{
			scanf("%d %s %d %s",&num,str,&num2,str2);
			m1 = check(str);
			m2 = check(str2);

			if (m1 == m2)
			{
				continue;
			}
			if (m1 == 1 && m2 == 2)
			{
				winarray[num]++;
				losearray[num2]++;
			}
			if (m1 == 2 && m2 == 1)
			{
				winarray[num2]++;
				losearray[num]++;
			}

			if (m1 == 1 && m2 == 3)
			{
				winarray[num2]++;
				losearray[num]++;
			}
			if (m1 == 3 && m2 == 1)
			{
				winarray[num]++;
				losearray[num2]++;
			}
			

			if (m1 == 2 && m2 == 3)
			{
				winarray[num]++;
				losearray[num2]++;
			}
			if (m1 == 3 && m2 == 2)
			{
				winarray[num2]++;
				losearray[num]++;
			}
		}
		
		for (int i = 1; i <= n; ++i)
		{
			// printf("%d\n", winarray[i]);
			// printf("%d\n", losearray[i]);
			if (!winarray[i] && !losearray[i])
			{
				printf("-\n");
			}
			else{
				printf("%.3lf\n",(double)((double)winarray[i]/(double)(winarray[i]+losearray[i])));
			}
		}
		flag = 1;
	}
	return 0;
}
	
