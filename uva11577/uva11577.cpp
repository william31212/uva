#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11577.in","r",stdin);
	freopen("uva11577.out","w",stdout);
	#endif


	char fuck[300];
	int times;
	scanf("%d",&times);
	getchar();

	while(times--)
	{
		fgets(fuck,300,stdin);

		int max = 0;
		int arr[26];
		fill(arr,arr+26,0);

		for (unsigned int i = 0; i < strlen(fuck) ; ++i)
		{
			if ((int)fuck[i] >= 65 && (int)fuck[i] <= 90)
			{
				arr[(int)fuck[i]-65]++;
			}

			if ((int)fuck[i] >= 97 && (int)fuck[i] <= 122)
			{
				arr[(int)fuck[i]-97]++;
			}

			
		}

		for (int i = 0; i < 26; ++i)
		{
			if ( arr[i] > max )
			{
				max = arr[i];
			}
		}

		for (int i = 0; i < 26; ++i)
		{
			if (arr[i] == max)
			{
				printf("%c",(char)(i+97));
			}
		}
		printf("\n");
	} 

	return 0;
}
	