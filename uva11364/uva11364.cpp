#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11364.in","r",stdin);
	freopen("uva11364.out","w",stdout);
	#endif

	int times;
	while(scanf("%d",&times) != EOF)
	{ 
		while(times--)
		{
			int store;
			int arr[100];
			scanf("%d",&store);
			for (int i = 0; i < store; ++i)
			{
				scanf("%d",&arr[i]);
			}
			sort(arr,arr+store);
			printf("%d\n", (arr[store-1] - arr[0]) * 2);
		} 
	} 

	return 0;
}
	