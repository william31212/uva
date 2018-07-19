#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12019.in","r",stdin);
	freopen("uva12019.out","w",stdout);
	#endif

	char *days[7] = { "Friday" , "Saturday", "Sunday" ,"Monday", "Tuesday", "Wednesday", "Thursday"};
	int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


	int times;
	while(scanf("%d",&times) != EOF)
	{
		int m,d;
		
		while(times--)
		{
			int day=0;
			scanf("%d %d",&m,&d);
			for (int i = 1; i < m; ++i)
			{
				day+=month[i];
			}

			day += d;

			printf("%s\n",days[day%7]);
		}
	} 
	
	return 0;
}
	
