#include <iostream>
#include <cstring>

using namespace std;

float ans = 0;

void check (char A)
{
	switch(A)
	{
		case 'W':
			ans+=1;
			break;
		case 'H':
			ans+=(float)1/(float)2;
			break;
		case 'Q':
			ans+=(float)1/(float)4;
			break;
		case 'E':
			ans+=(float)1/(float)8;
			break;
		case 'S':
			ans+=(float)1/(float)16;
			break;
		case 'T':
			ans+=(float)1/(float)32;
			break;
		case 'X':
			ans+=(float)1/(float)64;
			break;
	}


}




int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12195.in","r",stdin);
	freopen("uva12195.out","w",stdout);
	#endif

	char str[300];
	int correct = 0;

	while(1){
		fgets(str,300,stdin);
		if (str[0] == '*')
		{
			break;
		}

		for (unsigned int i = 0; i < strlen(str) - 1 ; ++i)
		{
			if(str[i] == '/')
			{
				for(int j = i+1 ; ; j++)
				{
					if (str[j] == '/')
					{
						break;
					}
					if (str[j] == '\n')
					{
						break;
					}
					check(str[j]);
					// printf("%f\n",ans);
				}

				if (ans == 1)
				{
					ans = 0;
					correct++;
				}
				else
				{
					ans = 0;
				}
			}
		}
		printf("%d\n",correct);
		correct = 0;
		ans = 0;
	}
	return 0;
}
	