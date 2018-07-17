#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11541.in","r",stdin);
	freopen("uva11541.out","w",stdout);
	#endif


	int times;
	char letter;
	int amount;
	bool flag=0;
	int count = 1;

	while(scanf("%d",&times) != EOF)
	{
		getchar();
		while(times)
		{
			scanf("%c",&letter);
			if (letter == ' ')
			{
				break;
			}
			if (letter == '\n')
			{
				printf("\n");
				flag = 0;
				times--;
				continue;
			}

			scanf("%d",&amount);
			if (!flag)
			{
				printf("Case %d: ", count++);
				flag = 1;
			}

			for (int i = 0; i < amount; ++i)
			{
				printf("%c",letter);
			}
		}
			
	} 
	return 0;
}
	