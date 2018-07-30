#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva118.in","r",stdin);
	freopen("uva118.out","w",stdout);
	#endif

	int arr[51][51];
	int ini_x,ini_y;
	int x,y;
	char face;
	int face_int;
	char road[100];

	for (int i = 0; i < 51; ++i)
	{
		for (int j = 0; j < 51; ++j)
		{
			arr[i][j] = 0;
		}
	}

	scanf("%d %d",&ini_x,&ini_y);
	while( scanf("%d",&x) != EOF )
	{
		scanf("%d %c",&y,&face);
		scanf("%s",road);

		switch (face)
		{
			case 'N':
				face_int = 1;
				break;
			case 'E':
				face_int = 2;
				break;
			case 'S':
				face_int = 3;
				break;
			case 'W':
				face_int = 4;
				break;
		}


		bool flag = 0;
		for (unsigned int i = 0; i < strlen(road); ++i)
		{
			if (road[i] == 'L')
			{
				if (face_int == 1)
				{
					face_int = 4;
				}
				else
				{
					face_int--;
				}
			}
			else if (road[i] == 'R')
			{
				if (face_int == 4)
				{
					face_int = 1;
				}
				else
				{
					face_int++;
				}
			}
			else if (road[i] == 'F' )
			{
				// printf("%d\n",face_int);
				switch(face_int)
				{
						case 1 :
						y = y + 1;
						if ( (x  > ini_x || y  > ini_y || x < 0 || y < 0) && arr[x][y - 1] == 0) 
						{
							arr[x][y - 1] = 1;
							y = y - 1;
							flag = 1;
							break;
						}
						else if ((x  > ini_x || y  > ini_y || x < 0 || y < 0) && arr[x][y - 1] == 1)
						{
							y = y - 1;
						}
						break;

		
					case 2 :
						x = x + 1;
						if ( (x  > ini_x || y  > ini_y || x < 0 || y < 0) && arr[x - 1][y] == 0) 
						{
							arr[x - 1][y] = 1;
							x = x - 1;
							flag = 1;
							break;
						}
						else if ((x  > ini_x || y  > ini_y || x < 0 || y < 0) && arr[x - 1][y] == 1)
						{
							x = x - 1;
						}
						break;


					case 3 :
						y = y - 1;
						if ( (x  > ini_x || y  > ini_y || x < 0 || y < 0 || x < 0 || y < 0) && arr[x][y + 1] == 0) 
						{
							arr[x][y + 1] = 1;
							y = y + 1;
							flag = 1;
							break;
						}
						else if ((x  > ini_x || y  > ini_y || x < 0 || y < 0) && arr[x][y + 1] == 1)
						{
							y = y + 1;
						}
						break;


					case 4 :
						x = x - 1;
						if ( (x  > ini_x || y  > ini_y || x < 0 || y < 0) && arr[x + 1][y] == 0) 
						{
							arr[x + 1][y] = 1;
							x = x + 1;
							flag = 1;
							break;
						}

						else if ((x  > ini_x || y  > ini_y || x < 0 || y < 0) && arr[x + 1][y] == 1)
						{
							x = x + 1;
						}
						break;

				}
				if (flag)
					break;
				// printf("%d %d\n", x,y);
				
			}

		}

		if (flag)
		{
			switch (face_int)
			{
				case 1 :
					face = 'N';
					break;
				case 2 :
					face = 'E';
					break;
				case 3 :
					face = 'S';
					break;
				case 4 :
					face = 'W';
					break;
			}
			printf("%d %d %c LOST\n",x ,y,face);
		}
			
		else
		{
			switch (face_int)
			{
				case 1 :
					face = 'N';
					break;
				case 2 :
					face = 'E';
					break;
				case 3 :
					face = 'S';
					break;
				case 4 :
					face = 'W';
					break;
			}
			printf("%d %d %c\n",x ,y ,face);
		}
	}



	return 0;
}
	