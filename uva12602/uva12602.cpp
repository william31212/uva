#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12602.in","r",stdin);
	freopen("uva12602.out","w",stdout);
	#endif


	int times;
	while(scanf("%d",&times) != EOF)
	{
		char letter1,letter2,letter3;
		char num1,num2,num3,num4;
		

		while(times--)
		{
			int sum_letter = 0;
			int sum_num = 0;
			getchar();
			scanf("%c%c%c-%c%c%c%c",&letter1,&letter2,&letter3,&num1,&num2,&num3,&num4);
			sum_letter += (letter1 - 'A') * 26 * 26;
			sum_letter += (letter2 - 'A') * 26;
			sum_letter += (letter3 - 'A');

			sum_num += (num1 - '0') * 10 * 10 * 10;
			sum_num += (num2 - '0') * 10 * 10;
			sum_num += (num3 - '0') * 10;
			sum_num += (num4 - '0');

			// printf("%d\n",sum_letter);
			// printf("%d\n",sum_num);


			if (abs(sum_letter - sum_num) <= 100) 
			{
				printf("nice\n");
			}
			else
			{
				printf("not nice\n");
			}
		}
	} 

	return 0;
}
	
