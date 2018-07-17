#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11494.in","r",stdin);
	freopen("uva11494.out","w",stdout);
	#endif


	while(1)
	{
		int x1 , y1 ,x2 , y2;
		scanf("%d %d %d %d" ,&x1,&y1,&x2,&y2);
		if (!x1 && !y1 && !x2 && !y2)
		{
			break;
		}

		if (x1 == x2 && y1 == y2)
		{
			printf("0\n");
		}

		else if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) //可直接走直,走橫,走協
		{
			printf("1\n");
		}
		else
		{
			printf("2\n");
		}

	} 
	return 0;
}
	
