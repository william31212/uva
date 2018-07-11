#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11185.in","r",stdin);
	freopen("uva11185.out","w",stdout);
	#endif

	long long int num = 0;

	while(scanf("%lld",&num) != EOF)
	{
		if (num < 0)
		{
			break;
		}

		bool flag = 0;
		int arr[100];
		int i = 0;
		fill(arr , arr+100 , 0);

		while(num > 0)
		{
			arr[i] = num % 3;
			num /= 3;
			i++;
			flag = 1;
		}

		if(!flag)
			printf("0");

		else
		{
			for (int j = i-1; j >= 0 ; --j)
			{
				printf("%d", arr[j]);
			}
		}


		printf("\n");
	}
	return 0;
}
	
