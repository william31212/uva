#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11689.in","r",stdin);
	freopen("uva11689.out","w",stdout);
	#endif


	int times;
	while(scanf("%d",&times) != EOF)
	{
		int e,f,c;
		
		
		while(times--)
		{
			int ans = 0;
			int tmp = 0;
			int tmpmo = 0;
			scanf("%d %d %d",&e,&f,&c);
			
			tmp = (e + f)/c;
			tmpmo = (e + f);
			tmpmo %= c;
			ans += tmp;
			tmp += tmpmo;
			
			while(tmp >= c)
			{
				tmpmo = tmp;
				tmpmo %= c;
				tmp /= c;
				ans += tmp;
				tmp += tmpmo;
			}
			printf("%d\n", ans);
		}
	} 

	return 0;
}
	