#include <iostream>
#include <algorithm>

using namespace std;

bool big_to_small(int i,int j)
{
	return (i>j);
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11369.in","r",stdin);
	freopen("uva11369.out","w",stdout);
	#endif


	int times;
	while(scanf("%d",&times) != EOF)
	{
		while(times--)
		{
			int arr[20000];
			int object;
			scanf("%d",&object);

			for (int i = 0; i < object; ++i)
			{
				scanf("%d",&arr[i]);
			}
			sort(arr,arr+object,big_to_small);

			if (object >= 3)
			{
				int sum = 0;
				for (int i = 2; i < object; i+=3)
				{
					sum += arr[i];
				}
				printf("%d\n", sum);
			}
			else 
			{
				printf("0\n");
			}
			
		}
	} 
	return 0;
}
	