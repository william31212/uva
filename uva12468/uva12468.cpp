#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12468.in","r",stdin);
	freopen("uva12468.out","w",stdout);
	#endif

	 
	int num1,num2;
	int tmp1,tmp2;
	while(scanf("%d %d",&num1,&num2) != EOF )
	{
		if (num1 == -1 && num2 == -1)
			break;
		tmp1 = abs(num1 - num2);
		tmp2 = 100 - abs(num1 - num2);

		if (tmp1 > tmp2)
		{
			printf("%d\n", tmp2);
		}

		else
		{
			printf("%d\n", tmp1);
		}

	} 

	return 0;
}
	
