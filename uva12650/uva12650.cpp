#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12650.in","r",stdin);
	freopen("uva12650.out","w",stdout);
	#endif


	int come,back;
	while(scanf("%d %d",&come,&back) != EOF)
	{
		bool arr[10001];
		fill(arr,arr+10001,0);
		if (come == back)
		{
			printf("*");
		}
		for (int i = 0; i < back; ++i)
		{
			int tmp;
			scanf("%d",&tmp);
			arr[tmp] = 1;
		}

		for (int i = 1; i <= come; ++i)
		{
			if (arr[i] == 0)
			{
				printf("%d ",i);
			}
		}
		printf("\n");

	} 
	return 0;
}
	