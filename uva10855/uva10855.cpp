#include <iostream>

using namespace std;

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("uva10855.in","r",stdin);
	freopen("uva10855.out","w",stdout);
	#endif

	int big,small;

	while(scanf("%d %d",&big,&small)!= EOF && big && small)
	{
		char b_square[big][big];
		char s_square[small][small];
		char degree_90[small][small];
		char degree_180[small][small];
		char degree_270[small][small];
		int arr[small*small];
		int check[small*small];
		fill(arr,arr+4,0);
		fill(check,check+4,0);
		getchar();

		for (int i = 0; i < big ; ++i)
		{
			for (int j = 0; j < big ; ++j)
			{
				scanf("%c",&b_square[i][j]);
			}
			getchar();
		}

		for (int i = 0; i < small ; ++i)
		{
			for (int j = 0; j < small ; ++j)
			{
				scanf("%c",&s_square[i][j]);
			}
			getchar();
		}

		if (small == 1)
		{
			degree_90[0][0] = degree_180[0][0] = degree_270[0][0] = s_square[0][0];
		}
		else
		{
			//rotate 90degree
			for (int i = 0; i < small; ++i)
			{
				for (int j = 0; j < small; ++j)
				{
					degree_90[j][small-1-i] = s_square[i][j];
				}
			}
			//rotate 180degree
			for (int i = 0; i < small; ++i)
			{
				for (int j = 0; j < small; ++j)
				{
					degree_180[j][small-1-i] = degree_90[i][j];
				}
			}
			//rotate 270degree
			for (int i = 0; i < small; ++i)
			{
				for (int j = 0; j < small; ++j)
				{
					degree_270[j][small-1-i] = degree_180[i][j];
				}
			}
		}
		
		
		int dif = big - small;
		int diftmp = dif;
		
	 	for (int k = 0; k <= diftmp; ++k)
		{
			dif = big - small + 1;
			int counter = 0;

			while(dif--)
			{
				for (int i = 0; i < small; ++i)
				{
					for (int j = 0; j < small; ++j)
					{
						if (b_square[k + i][j + counter] == s_square[i][j] )
						{
							arr[0]++;
						}

						if (b_square[k + i][j + counter] == degree_90[i][j] )
						{
							arr[1]++;
						}
						if (b_square[k + i][j + counter] == degree_180[i][j] )
						{
							arr[2]++;
						}
						if (b_square[k + i][j + counter] == degree_270[i][j] )
						{
							arr[3]++;
						}
					}
					
				}
				counter++;



				for (int i = 0; i < 4; ++i)
				{
					if (arr[i] == small*small)
					{
						arr[i]-=small*small;
						check[i]++;
					}
					else
					{
						arr[i] = 0;
					}
				}

			}
		}
		
		
		printf("%d %d %d %d\n",check[0],check[1],check[2],check[3]);
		
	}

	return 0;
	
}
	
