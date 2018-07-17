#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11498.in","r",stdin);
	freopen("uva11498.out","w",stdout);
	#endif
	int times;
	int midx , midy;
	int x , y;

	while( scanf("%d",&times) != EOF && times)
	{
		scanf("%d %d",&midx,&midy);
		while(times--)
		{
			scanf("%d %d",&x,&y);

			if ( (midx == x && midy != y) || (midx != x && midy == y) || (midx == x && midy == y) )
			{
				printf("divisa\n");
			}

			else if ( x < midx && y < midy )
			{
				printf("SO\n");
			}
			else if ( x > midx && y < midy )
			{
				printf("SE\n");
			}
			else if ( x < midx && y > midy )
			{
				printf("NO\n");
			}
			else if ( x > midx && y > midy )
			{
				printf("NE\n");
			}

		}
		
	} 

	return 0;
}
	