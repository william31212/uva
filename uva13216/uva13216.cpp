#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva13216.in","r",stdin);
	freopen("uva13216.out","w",stdout);
	#endif

	int one_bit[2] = {1,6};
	int the_same[10] = {7,1,5,9,3,7,1,5,9,3};

	int times;
	scanf("%d",&times);

	while(times--)
	{
		char num[2000];
		scanf("%s",num);
		// printf("%s\n", num);
		if (strlen(num) == 1)
		{
			if (num[0] == '0')
			{
				printf("%d\n", one_bit[ num[0] - '0' ]);
			}
			else if (num[0] == '1')
			{
				printf("%d6\n", one_bit[ num[0] - '0']);
			}
			else
			{
				for (int i = 2; i <= 9; ++i)
				{
					if ( num[0] - '2' + 2 == i )
					{
						printf("%d6\n", the_same[i]);
						break;
					}
				}
			}	
		}


		else if ( strlen(num) >= 2)
		{
			for (int i = 0; i <= 9; ++i)
			{
				if ( num[strlen(num) - 1] - '0' == i )
				{
					printf("%d6\n", the_same[i]);
					break;
				}
			}
		}

	}
	return 0;
}
	