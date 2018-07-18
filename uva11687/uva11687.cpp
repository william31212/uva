#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11687.in","r",stdin);
	freopen("uva11687.out","w",stdout);
	#endif

	char str[1000000];

	while(scanf("%s",str) != EOF)
	{
		if (!strcmp(str,"END"))
			break;

		if (strlen(str) == 1)
		{
			if (!strcmp(str,"1"))
			{
				printf("1\n");
			}
			else
			{
				printf("2\n");
			}
		}

		else if ( 2 <= strlen(str)  && strlen(str) <= 9)
		{
			printf("3\n");
		}

		else if ( strlen(str) >= 10)
		{
			printf("4\n");
		}

	} 
	return 0;
}

