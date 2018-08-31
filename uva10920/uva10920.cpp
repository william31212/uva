#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("uva10920.in","r",stdin);
	freopen("uva10920.out","w",stdout);
	#endif

	int edge,step;
	int arr[50001];
	for(int i = 0; i < 50001 ; i++)//第一層尾端是1，第二尾層端是9
	{
		arr[i] = (i * 2) - 1;
		arr[i] = arr[i] * arr[i];
	}
	while(scanf("%d %d",&edge,&step) != EOF && edge && step)
	{
		int center = (edge + 1) / 2;
		int dif = 0;
		int start = 0;
		int tmp;

		for (int i = 0; i < 50001; ++i)
		{
			if (step <= arr[i])
			{
				tmp = i;
				dif = arr[i] - step;
				start = center + i - 1;
				break;
			}
		}

		int x = start;
		int y = start;
		int length = sqrt(arr[tmp]) - 1;
		int count = 0;
		int direction = 1;


		if (step == 1)
		{
			printf("Line = %d, column = %d.\n",y+1,x+1);
		}
		else
		{
			while(dif)
			{
				if (count != length && direction == 1)
				{
					y -= 1;
					count++;
				}
				
				if (count != length && direction == 2)
				{
					x -= 1;
					count++;
				}

				if (count != length && direction == 3)
				{
					y += 1;
					count++;
				}

				if (count != length && direction == 4)
				{
					x += 1;
					count++;
				}
	
				if (count == length)
				{
					if (direction == 4)
					{
						direction = 1;
					}
					else
					{
						direction++;
					}
					count = 0;
				}


				dif--;
			}

			printf("Line = %d, column = %d.\n",y,x);
		}

	}
	return 0;
}