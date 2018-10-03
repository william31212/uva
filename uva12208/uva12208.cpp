#include <bits/stdc++.h>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12208.in","r",stdin);
	freopen("uva12208.out","w",stdout);
	#endif


	long long int start,end;
	int cnt = 1;
	while(scanf("%lld %lld",&start,&end) != EOF && (!!start + !!end))
	{
		long long int ans_1 = 0;
		end += 1;
		for (long long int i = 2; i <= (1LL << 31) ; i = (i << 1))
		{
			ans_1 += (end / i) * (i / 2);
			if (end % i > i/2)
			{
				ans_1 += (end % i) - (i / 2);
			}

			ans_1 -= (start / i) * (i / 2);
			if (start % i > i/2)
			{
				ans_1 -= ( (start % i) - (i / 2) );
			}
		}
		printf("Case %d: %lld\n",cnt,ans_1);
		cnt++;
	} 
	return 0;
}
	