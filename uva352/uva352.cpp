#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva353"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

char arr[30][30];
char success[30][30];
int times = 0;

int walk(int i , int j ,int edge)
{ 
	if (i-1 >= 0 && j-1 >= 0 && i-1 < edge && j-1 < edge && arr[i][j] == '1' && arr[i-1][j-1] == '1' && success[i-1][j-1] != '1')
	{
		success[i-1][j-1] = '1';
		times = 1;
		walk(i-1,j-1,edge);
	}
	if (i-1 >= 0 && j >= 0 && i-1 < edge && j < edge && arr[i][j] == '1' && arr[i-1][j] == '1' && success[i-1][j] != '1')
	{
		success[i-1][j] = '1';
		times = 1;
		walk(i-1,j,edge);
	}
	if (i-1 >= 0 && j+1 >= 0 && i-1 < edge && j+1 < edge && arr[i][j] == '1' && arr[i-1][j+1] == '1' && success[i-1][j+1] != '1')
	{
		success[i-1][j+1] = '1';
		times = 1;
		walk(i-1,j+1,edge);
	}



	if (i >= 0 && j-1 >= 0 && i < edge && j-1 < edge && arr[i][j] == '1' && arr[i][j-1] == '1' && success[i][j-1] != '1')
	{
		success[i][j-1] = '1';
		times = 1;
		walk(i,j-1,edge);
	}
	if (i >= 0 && j+1 >= 0 && i < edge && j+1 < edge && arr[i][j] == '1' && arr[i][j+1] == '1' && success[i][j+1] != '1')
	{
		success[i][j+1] = '1';
		times = 1;
		walk(i,j+1,edge);
	}


	if (i+1 >= 0 && j-1 >= 0 && i+1 < edge && j-1 < edge && arr[i][j] == '1' && arr[i+1][j-1] == '1' && success[i+1][j-1] != '1')
	{
		success[i+1][j-1] = '1';
		times = 1;
		walk(i+1,j-1,edge);
	}
	if (i+1 >= 0 && j >= 0 && i+1 < edge && j < edge && arr[i][j] == '1' && arr[i+1][j] == '1' && success[i+1][j] != '1')
	{
		success[i+1][j] = '1';
		times = 1;
		walk(i+1,j,edge);
	}
	if (i+1>= 0 && j+1 >= 0 && i+1 < edge && j+1 < edge && arr[i][j] == '1' && arr[i+1][j+1] == '1' && success[i+1][j+1] != '1')
	{
		success[i+1][j+1] = '1';
		times = 1;
		walk(i+1,j+1,edge);
	}

	if (arr[i][j] == '1' && success[i][j] != '1' && times == 0)
	{
		times = 1;
	}

	return times;
}



int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int edge;
	int cnt = 1;
	
	while(scanf("%d",&edge) != EOF)
	{
		int ans = 0;
		memset(arr,'0',sizeof(arr));
		memset(success,'0',sizeof(success));

		getchar();
		for (int i = 0; i < edge; ++i)
		{
			for (int j = 0; j < edge; ++j)
			{
				scanf("%c",&arr[i][j]);
			}
			getchar();
		}
		// printf("fuck\n");
		for (int i = 0; i < edge; ++i)
		{
			for (int j = 0; j < edge; ++j)
			{
				times = 0;
				int tmp = walk(i,j,edge);
				// printf("i:%d j:%d : %d\n",i,j,tmp);
				// printf("%c\n", arr[i][j]);
				ans += tmp;
			}
		}
		
		printf("Image number %d contains %d war eagles.\n",cnt++ ,ans);

	}

	return 0;
}