#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("uva10409.in","r",stdin);
	freopen("uva10409.out","w",stdout);
	#endif

	int times;
	
	char fuck[10];

	while(scanf("%d ",&times) != EOF && times)
	{
		int dice_up = 1;
		int dice_down = 6;
		int dice_west = 3;
		int dice_east = 4;
		int dice_north = 2;
		int dice_south = 5;
		while(times--)
		{
			scanf("%s",fuck);
			if (fuck[0] == 'n')
			{
				dice_north = dice_up;
				dice_up = dice_south;
				dice_down = 7 - dice_up; 
				dice_south = 7 - dice_north;
			}
			if (fuck[0] == 's')
			{
				dice_south = dice_up;//up to south
				dice_up = dice_north;//north to up
				dice_north = 7 - dice_south;
				dice_down = 7 - dice_up;
	
			}
			if (fuck[0] == 'e')
			{
				dice_east = dice_up;
				dice_up = dice_west;
				dice_down = 7 - dice_up;
				dice_west = 7 - dice_east;		
			}
			if (fuck[0] == 'w')
			{
				dice_west = dice_up;
				dice_up = dice_east;
				dice_east = 7 - dice_west;
				dice_down = 7 - dice_up;		
			}
		}
		printf("%d\n", dice_up);
	}
	
	return 0;

}