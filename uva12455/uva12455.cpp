#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("uva12455.in","r",stdin);
	freopen("uva12455.out","w",stdout);
	#endif

    int times;
    int want,kind;
    int bars;

    scanf("%d",&times);

    while(times--)
    {
    	int dp[1005];
    	memset(dp,0,sizeof(dp));

    	dp[0] = 1;
    	scanf("%d",&want);
    	scanf("%d",&kind);

    	for (int i = 0; i < kind; ++i)
    	{
    		scanf("%d",&bars);

    		for (int j = want-bars; j >= 0 ; j--)//initiail state is 0+bars,so dp[0+bats] is itself so it can.
    		{
    			if (dp[j] && !dp[j+bars])//dp[j] can, dp[j+bars] can,too.
    			{
    				dp[j+bars] = 1;
    			}
    		}
    	}
    	if (dp[want])
    		printf("YES\n");
 		else
 			printf("NO\n");
    }

	return 0;

}