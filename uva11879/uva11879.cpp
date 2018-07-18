#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11879.in","r",stdin);
	freopen("uva11879.out","w",stdout);
	#endif

	char num[1000];

	while(scanf("%s",num) != EOF && strcmp(num,"0"))
	{
		int arr[1000];
		for (unsigned int i = 0; i < strlen(num); ++i)
		{
			arr[i] = (int)num[i] - 48 ;
		}

		arr[strlen(num)] = 0;

		for (unsigned int i = 0; i < strlen(num); ++i)
		{
			arr[i+1] += (arr[i]%17) * 10;
		}

		if (!arr[strlen(num)])
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}


	}

	return 0;
}
	
