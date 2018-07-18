#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11875.in","r",stdin);
	freopen("uva11875.out","w",stdout);
	#endif


	int times;
	while(scanf("%d",&times) != EOF)
	{
		int count = 1;
		while(times--)
		{
			int length;
			int arr[30];
			scanf("%d",&length);

			for (int i = 0; i < length; ++i)
			{
				scanf("%d",&arr[i]);
			}

			printf("Case %d: %d\n",count++,arr[(length-1)/2]);
		}
	} 

	return 0;
}
	
