#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11479.in","r",stdin);
	freopen("uva11479.out","w",stdout);
	#endif


	int times;
	while( scanf("%d",&times) != EOF)
	{
		int count = 1;
		while(times--)
		{
			long long int a , b , c;
			scanf("%lld %lld %lld",&a,&b,&c);

			if ( (a+b) > c && (b+c) > a && (a+c) > b)
			{
				if (a == b && b == c)
				{
					printf("Case %d: Equilateral\n",count++);
				}
				else if ( (a==b && b!=c) || (a!=b && b==c) || (a==c && b!=c)) 
				{
					printf("Case %d: Isosceles\n",count++);
				}
				else if (a!=b && b!=c)
				{
					printf("Case %d: Scalene\n",count++);
				}
			}

			else
			{
				printf("Case %d: Invalid\n",count++);
			}
		}
	} 

	return 0;
}
	