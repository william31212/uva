#include <iostream>
#include <cstdio>
#include <cstring>
#include <array>

using namespace std;

bool prime[20000];

void table()
{
	prime[0] = 0;
	prime[1] = 1;
	fill( prime+0 , prime+20000 , 1);
	for( unsigned int i = 2; i < 20000 ; i++)
	{
		if( prime[i] )
		{
			for (unsigned int j = i + i ; j < 20000; j += i)
			{
				prime[j] = 0;
			}
		}
	}
} 



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10924.in","r",stdin);
	freopen("uva10924.out","w",stdout);
	#endif
	char input[20];
	table();
	while( scanf("%s",input)!=EOF ){
		int sum = 0;
		for (unsigned int i = 0; i < strlen(input); ++i)
		{
			if( 65 <= input[i] &&  input[i] <= 90)
				sum += (int)input[i] - 38;
			if (97 <= input[i] &&  input[i] <= 122)
				sum += (int)input[i] - 96;
		}
		

		if ( prime[sum] )
		{
			printf("It is a prime word.\n");
		}
		else
		{
			printf("It is not a prime word.\n");
		}
	}

	return 0;
}
	