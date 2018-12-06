#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva294"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long LL;  
bool label[40000];
vector <int> prime;
vector <int> len;


void build()
{
	memset(label,0,sizeof(label));

	label[0] = 1;
	label[1] = 1;
	for (int i = 2; i < 40000; ++i)
	{
		for (int j = i+i; j < 40000; j += i)
		{
			label[j] = 1;
		}
		
		if (!label[i])
		{
			prime.push_back(i);	
		}
	}

}

void print()
{
	for (int i = 0; i < prime.size(); ++i)
	{
		printf("%d ",prime[i]);
	}
}

LL getdiv(LL num)
{
	LL anss = 1;
	LL tmp = num;
	for (int i = 0; i < 500; ++i)
	{	
		LL cnt = 0;
		while(num % prime[i] == 0)
		{
			// printf("%d\n",prime[i]);
			cnt++;
			num /= prime[i];
		}
		if (cnt == 0)
		{
			continue;
		}
		else
		{
			anss *= (cnt + 1);
		}
		// printf("%d:%d\n",tmp,prime[i] );
	}
	// printf("\n");
	return anss;
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	LL num1,num2;
	LL ans = 0,anscnt = 0,tmp = 0,tmpcnt = 0;

	build();
	// print();

	scanf("%d",&times);

	while(times--)
	{
		scanf("%lld %lld",&num1,&num2);

		ans = 0;
		anscnt = 0;
		tmp = 0;
		tmpcnt = 0;

		for (LL i = num1; i <= num2; ++i)
		{
			tmpcnt = getdiv(i);
			tmp = i;

			if (tmpcnt > anscnt)
			{
				anscnt = tmpcnt;
				ans = tmp;
			}

		}
		
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",num1,num2,ans,anscnt);

	}
	return 0;
}