#include <bits/stdc++.h>

using namespace std;

int binary_search(int arr[],int left,int right,int target)
{
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if (target >= arr[mid])
		{
			if (arr[mid] == target)
			{
				return mid + 1;
			}
			else
			{
				left = mid + 1;
			}
			
		}
		else
		{
			right = mid;
		}
	}
	return left;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12908.in","r",stdin);
	freopen("uva12908.out","w",stdout);
	#endif

	int num;
	int arr[15000];

	for (int i = 0; i < 15000; ++i)
	{
		if (i == 0)
			arr[i] = 1;
		else
			arr[i] = (i + 1) + arr[i-1];
	}

	// for (int i = 1; i <= 134; ++i)
	// {
	// 	printf("%d\n", arr[i]);
	// }

	while(scanf("%d",&num) && num)
	{
		int position;
		// for (int i = 0; i < 15000 ; ++i)
		// {
		// 	if (num >= arr[i])
		// 	{
		// 		position = i+1; 
		// 	}
		// }

		position = binary_search(arr,1,15000,num);

		printf("%d %d\n",arr[position] - num ,position+1);

	}
	return 0;
}
	
