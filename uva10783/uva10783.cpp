#include <iostream>
#include <cstdio>

using namespace std;

void swapp(int *a,int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10783.in","r",stdin);
	freopen("uva10783.out","w",stdout);
	#endif

	int times = 0;
	int count = 1;
	scanf("%d",&times);
	while(times--)
	{
		int a = 0,b = 0;
		int sum = 0;
		scanf("%d",&a);
		scanf("%d",&b);
		if(a > b)
		{
			swapp(&a,&b);
		}
		
		for (int i = a; i <= b; ++i)
		{
				if(i % 2 != 0)
				{
					sum += i;
				}
		}

		printf("Case %d: %d\n",count,sum);
		count++;
	}
	return 0;
}
	
