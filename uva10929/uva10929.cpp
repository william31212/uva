#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10929.in","r",stdin);
	freopen("uva10929.out","w",stdout);
	#endif
	char num[1000];
	int num_int[1000];

	while(scanf("%s",num) != EOF)
	{
		int sum_odd = 0 , sum_even = 0;

		if (strlen(num) == 1 && num[0] == '0')
		{
			break;
		}


		for (unsigned int i = 0; i < strlen(num); ++i)
		{
			num_int[i] = num[i] - 48;

			if (i % 2 == 0)
			{
				sum_odd += num_int[i];
			}

			else
			{
				sum_even += num_int[i];
			}
		}

		if ( abs(sum_odd - sum_even) % 11 == 0 )
		{
			printf("%s is a multiple of 11.\n", num);
		}

		else
		{
			printf("%s is not a multiple of 11.\n", num);
		}

		fill(num , num + 1000 , '0');
		fill(num_int , num_int + 1000 , 0);
	}

	return 0;
}
	