#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12149.in","r",stdin);
	freopen("uva12149.out","w",stdout);
	#endif


	int num;
	while(scanf("%d",&num) != EOF && num)
	{
		num = num * (num+1) * (2 * num + 1) /6;
		printf("%d\n",num);
	} 

	return 0;
}
	