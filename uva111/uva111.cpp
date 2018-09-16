#include <bits/stdc++.h>

using namespace std;

const int n1 = 20 , n2 = 20;
int s1[20+1];
int s2[20+1];
int length[20+1][20+1];
int preve[20+1][20+1];
int len[20];




int lcs(int lo)
{
	for (int i = 0; i <= lo; ++i)
		length[i][0] = 0;
	for (int i = 0; i < lo; ++i)
		length[0][i] = 0;

	for (int i = 1; i <= lo; ++i)
	{
		for (int j = 1; j <= lo; ++j)
		{
			if (s1[i] == s2[j])
			{
				length[i][j] = length[i-1][j-1] + 1;
				preve[i][j] = 0; // oblique
			}
			else
			{	
				if (length[i-1][j] < length[i][j-1])//up < left
				{
					length[i][j] = length[i][j-1];//come left
					preve[i][j] = 1; // 左方
				}
				else
				{
					length[i][j] = length[i-1][j];//come up
					preve[i][j] = 2; // 上方
				}
			}
		}
	}

	return length[lo][lo];


}



int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endifs
	
	int lo;
	int tmp;
	scanf("%d",&lo);

	for (int i = 1; i <= lo; ++i)
	{
		scanf("%d",&tmp);
		s1[tmp] = i;
	}


	while(~scanf("%d",&tmp))
	{
		s2[tmp] = 1;

		for (int i = 2; i <= lo; ++i)
		{
			scanf("%d",&tmp);
			s2[tmp] = i; 
		}
		printf("%d\n",lcs(lo));
	}
	return 0;

}