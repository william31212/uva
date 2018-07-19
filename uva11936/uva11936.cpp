#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11936.in","r",stdin);
	freopen("uva11936.out","w",stdout);
	#endif


	int times;
	while(scanf("%d",&times) != EOF)
	{	
		int a,b,c;
		while(times--)
		{
			scanf("%d %d %d",&a,&b,&c);

			if ( (a+b) <= c  || (b+c) <= a || (a+c) <= b) 
			{
				printf("Wrong!!\n");
			}

			else
			{
				printf("OK\n");
			}
		}
	} 
	return 0;
}
	
