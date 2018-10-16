#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11352"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

char arr[105][105];
int MAP[105][105];
int row,column;
int start_i,start_j,end_i,end_j;
int que_layer = 0;

queue < pair<int , int > > que;
//3 have horse
//100 start
//200 end


void horse(int i,int j)
{
	MAP[i][j] = 3;
	//right
	if (i - 2 >= 0 && i - 2 <= row && j + 1 >= 0 && j + 1 <= column )
	{
		if ( MAP[i - 2][j + 1] != 100 && MAP[i-2][j + 1] != 200)
		{
			MAP[i - 2][j + 1] = 3;
		}
	}
	if (i - 1 >= 0 && i - 1 <= row && j + 2 >= 0 && j + 2 <= column )
	{
		if ( MAP[i - 1][j + 2] != 100 && MAP[i - 1][j + 2] != 200)
		{
			MAP[i - 1][j + 2] = 3;
		}
	}
	if (i + 1 >= 0 && i + 1 <= row && j + 2 >= 0 && j + 2 <= column )
	{
		if ( MAP[i + 1][j + 2] != 100 && MAP[i + 1][j + 2] != 200)
		{
			MAP[i + 1][j + 2] = 3;
		}
	}
	if (i + 2 >= 0 && i + 2 <= row && j + 1 >= 0 && j + 1 <= column )
	{
		if ( MAP[i + 2][j + 1] != 100 && MAP[i + 2][j + 1] != 200)
		{
			MAP[i + 2][j + 1] = 3;
		}
	}

	//left
	if (i - 2 >= 0 && i - 2 <= row && j - 1 >= 0 && j - 1 <= column )
	{
		if ( MAP[i - 2][j - 1] != 100 && MAP[i - 2][j - 1] != 200)
		{
			MAP[i - 2][j - 1] = 3;
		}
	}
	if (i - 1 >= 0 && i - 1 <= row && j - 2 >= 0 && j - 2 <= column )
	{
		if ( MAP[i - 1][j - 2] != 100 && MAP[i - 1][j - 2] != 200)
		{
			MAP[i - 1][j - 2] = 3;
		}
	}
	if (i + 1 >= 0 && i + 1 <= row && j - 2 >= 0 && j - 2 <= column )
	{
		if ( MAP[i + 1][j - 2] != 100 && MAP[i + 1][j - 2] != 200)
		{
			MAP[i + 1][j - 2] = 3;
		}
	}
	if (i + 2 >= 0 && i + 2 <= row && j - 1 >= 0 && j - 1 <= column )
	{
		if ( MAP[i + 2][j - 1] != 100 && MAP[i + 2][j - 1] != 200)
		{
			MAP[i + 2][j - 1] = 3;
		}
	}

}

int bfs(int i,int j)
{
	if (i - 1 >= 0 && j - 1 >= 0 && i - 1 < row && j - 1 < column )
	{
		if (MAP[i-1][j-1] == 0)
		{
			MAP[i-1][j-1] = 3;
			que.push(make_pair(i-1,j-1));
			que_layer++;
		}
		if (i - 1 == end_i && j - 1 == end_j)
		{
			return 0;
		}
		
	}
	if (i - 1 >= 0 && j >= 0 && i - 1 < row && j < column )
	{
		if (MAP[i-1][j] == 0)
		{
			MAP[i-1][j] = 3;
			que.push(make_pair(i-1,j));
			que_layer++;
		}
		if (i - 1 == end_i && j  == end_j)
		{
			return 0;
		}
	}
	if (i - 1 >= 0 && j + 1 >= 0 && i - 1 < row && j + 1 < column )
	{
		if (MAP[i-1][j+1] == 0)
		{
			MAP[i-1][j+1] = 3;
			que.push(make_pair(i-1,j+1));
			que_layer++;
		}
		if (i - 1 == end_i && j + 1 == end_j)
		{
			return 0;
		}
	}



	if (i >= 0 && j - 1 >= 0 && i < row && j - 1 < column )
	{
		if (MAP[i][j-1] == 0)
		{
			MAP[i][j-1] = 3;
			que.push(make_pair(i,j-1));
			que_layer++;
		}
		if (i == end_i && j - 1 == end_j)
		{
			return 0;
		}
	}
	if (i >= 0 && j + 1 >= 0 && i < row && j + 1 < column )
	{
		if (MAP[i][j+1] == 0)
		{
			MAP[i][j+1] = 3;
			que.push(make_pair(i,j+1));
			que_layer++;
		}
		if (i  == end_i && j + 1 == end_j)
		{
			return 0;
		}
	}




	if (i + 1 >= 0 && j - 1 >= 0 && i + 1 < row && j - 1 < column )
	{
		if (MAP[i+1][j-1] == 0)
		{
			MAP[i+1][j-1] = 3;
			que.push(make_pair(i+1,j-1));
			que_layer++;
		}
		if (i + 1 == end_i && j - 1 == end_j)
		{
			return 0;
		}
	}
	if (i + 1 >= 0 && j >= 0 && i + 1 < row && j < column )
	{
		if (MAP[i+1][j] == 0)
		{
			MAP[i+1][j] = 3;
			que.push(make_pair(i+1,j));
			que_layer++;
		}
		if (i + 1 == end_i && j == end_j)
		{
			return 0;
		}
	}
	if (i + 1 >= 0 && j + 1 >= 0 && i + 1 < row && j + 1 < column )
	{
		if (MAP[i+1][j+1] == 0)
		{
			MAP[i+1][j+1] = 3;
			que.push(make_pair(i+1,j+1));
			que_layer++;
		}
		if (i + 1 == end_i && j + 1 == end_j)
		{
			return 0;
		}
	}

	return 1;
	
}





int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	
	int times;
	scanf("%d",&times);
	while(times--)
	{
		memset(arr,'0',sizeof(arr));
		memset(MAP,0,sizeof(MAP));
		que_layer = 0;
		while (!que.empty())//清空que
		{
			que.pop();	
		}

		scanf("%d %d",&row,&column);
		getchar();
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < column; ++j)
			{
				scanf("%c",&arr[i][j]);
				if (arr[i][j] == 'A')
				{
					start_i = i;
					start_j = j;
					MAP[i][j] = 100;
				}
				if (arr[i][j] == 'B')
				{
					end_i = i;
					end_j = j;
					MAP[i][j] = 200;
				}
				if (arr[i][j] == 'Z')
				{
					horse(i,j);
				}
			}
			getchar();
		}

		int ans = 0;
		bool flag = 0;
		int tmp = 0;

		// first-layer start
		if( bfs(start_i,start_j) == 0 )
		{
			ans += 1;
			printf("Minimal possible length of a trip is %d\n", ans);
			continue;
		}
		else
		{
			tmp = que_layer;
		}
		ans = 1;

		while(!que.empty())
		{	
			tmp = que_layer;
			que_layer = 0;
			while(tmp--)
			{
				start_i = que.front().first;
				start_j = que.front().second;
				if(bfs(start_i,start_j) == 1)
				{
					if (que.empty())
					{
						flag = 0;
						break;
					}
					que.pop();
				}
				else
				{
					flag = 1;
					break;
				}	
			}
			ans += 1;
			if (flag)
				break;
		}
		if (!flag)
		{
			printf("King Peter, you can't go now!\n");
		}
		else
		{
			printf("Minimal possible length of a trip is %d\n", ans);
		}
	} 
	return 0;
}