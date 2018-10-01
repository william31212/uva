#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}
}



int main()
{
	#ifdef DBG
	freopen("uva11417.in","r",stdin);
	freopen("uva11417.out","w",stdout);
	#endif

	int num;
	while(cin >> num && num)
	{
		int G = 0;
		for(int i=1;i<num;i++)
		{
			for(int j=i+1;j<=num;j++)
			{
				G += gcd(i,j);
			}
		}
		printf("%d\n", G);
	}


	
	return 0;

}