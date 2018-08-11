#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva130.in","r",stdin);
	freopen("uva130.out","w",stdout);
	#endif


	int n,k;
	int arr[101];
	int dead_amonut,next,is_dead;
	int next_counter;
	int dead_tmp_position;

	while(scanf("%d %d",&n,&k) != EOF && n && k)
	{
		fill(arr , arr+101 , 0);
		for (int i = 0; i < n; ++i) 
		{
			arr[i] = i + 1;
		}

		dead_amonut = 0;
		next = 0;
		is_dead = 1;

		while( dead_amonut < n - 1) 
		{
			next_counter = 0; //下一個數數器

			while(1)
			{
				if ( arr[next] != 0)//下面一位不是0，就計數器加1
				{
					next_counter++;

				}

				if (next_counter == k)//數到第k個跳出迴圈
				{
					break;
				}

				next = (next + 1) % n;
			}

			

			if ( is_dead == 1 ) // 死掉
			{
				//printf("dead -> %d\n", arr[next]);
				arr[next] = 0;
				dead_amonut++;
				dead_tmp_position = next;
			}

			else //找到第k個移形換位
			{
				arr[dead_tmp_position] = arr[next];
				arr[next] = 0;
				next = (dead_tmp_position + 1) % n; //從他的下一位開始
			}

			if (!is_dead)//沒殺人改要殺人
			{
				is_dead = 1;
			}
			else//要殺人改沒殺人
			{
				is_dead = 0;
			}
		}

		int ans;

		for (int i = 0; i < n; ++i)
		{	
			if (arr[i] != 0)//看誰活下來
			{
				ans = i;
				break;
			}
		}

		if (arr[ans] == 1)
		{
			printf("1\n"); //就是i=1
		}
		else
		{
			printf("%d\n",1 + (n - arr[ans] + 1) ); //第一個加上剩下誰就是i=多少的時候就是1號
		}
		/*
		i    survie     
		1 ->   4
		2 ->   5
		3 ->   1   
		4 ->   2
		5 ->   3

		答案是要輸出 3
		*/

	}

	return 0;
}
	