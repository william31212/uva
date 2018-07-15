#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11398.in","r",stdin);
	freopen("uva11398.out","w",stdout);
	#endif

	
	char str[500];
	bool flag = 0; 
	int num[100];
	int k = 0;
	

	while(scanf("%s",str) != EOF && str[0] != '~')
	{
		if (str[0] == '#')
		{
			int sum = 0;
			int plus = 0;

			for (int i = k-1; i >= 0; --i)
			{

				sum += num[i] * pow(2.0 , plus);
				plus++;
			}

			printf("%d\n",sum);
			k = 0;
		}

		else if (strlen(str) == 1)
		{
			flag = 1;
		}

		else if (strlen(str) == 2)
		{
			flag = 0;
		}

		else
		{
			for (unsigned int i = 0; i < strlen(str) - 2 ; ++i)
			{
				num[k] = flag;
				k++;
			}
		}
	} 

	return 0;
}
	
