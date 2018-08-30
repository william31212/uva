#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva357.in","r",stdin);
	freopen("uva357.out","w",stdout);
	#endif

	int coin[4]={5,10,25,50};
	long long kind[30005];

	fill(kind,kind+30005,1);


	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j <= 30000 ; ++j)
		{
			if (j >= coin[i])
			{
				kind[j] += kind[j - coin[i]];
			}
		}
	}

	// for (int i = 1; i <= 30000; ++i)
	// {
	// 	printf("%lld\n", kind[i]);
	// }
	
	
	int num;
	while(scanf("%d",&num)!= EOF)
	{
		if (kind[num] == 1)
		{
			printf("There is only 1 way to produce %d cents change.\n",num);
		}
		else
		{
			printf("There are %lld ways to produce %d cents change.\n",kind[num],num);
		}
	}



	return 0;
}


	
