#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12289.in","r",stdin);
	freopen("uva12289.out","w",stdout);
	#endif

	int times;
	char input[5];
	while(scanf("%d",&times) != EOF)
	{
		while(times--)
		{
			int check = 0;
			scanf("%s",input);

			if (strlen(input) == 3)
			{
				if (input[0] == 'o')
				{
					check++;
				}
				if (input[1] == 'n')		
				{
					check++;
				}
				if (input[2] == 'e')
				{
					check++;
				}
			}
			else if (strlen(input) == 5)
			{
				printf("3\n");
				continue;
			}

			if (check >= 2)
			{
				printf("1\n");
			}
			else
			{
				printf("2\n");
			}
		}
	} 
	


	return 0;
}
	
