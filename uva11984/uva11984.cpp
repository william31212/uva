#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11984.in","r",stdin);
	freopen("uva11984.out","w",stdout);
	#endif


	int times;
	while(scanf("%d",&times) != EOF)
	{
		float C,dif;
		int count=1;
		while(times--)
		{	
			double F = 0;
			scanf("%f %f",&C,&dif);

			F =  ((C * 9) / 5) + 32;

			F += dif;

			F = (F-32) * 5 / 9;

			printf("Case %d: %.2lf\n",count++, F);
		}

	
	} 

	return 0;
}
	
