#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva12416.in","r",stdin);
	freopen("uva12416.out","w",stdout);
	#endif	

	char s;
	int cnt = 0;
	int Max = 0;
	while(scanf("%c",&s) != EOF)
	{	
		
		if (s == '\n')
		{
			if ((log(Max)/log(2)) - (int)(log(Max)/log(2)) == 0)
			{
				printf("%d\n", (int)(log(Max)/log(2)));
			}
			else
			{
				printf("%d\n", (int)(log(Max)/log(2)) + 1 );
			}
			
			cnt = 0;
			Max = 0;
			continue;
		}

		if (s == ' ')
		{
			cnt++;
			while(scanf("%c",&s))
			{
				if (s == ' ')
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
		}

		Max = max(cnt,Max);
		cnt = 0;
	}
	return 0;
}