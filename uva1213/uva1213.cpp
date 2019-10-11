#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva1213"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

bool flag[1125];
int dp[1125][15];

vector<int> prime;


void build()
{
	memset(flag,0,sizeof(0));
	for(int i = 2; i < 1125; i++)
	{
		if(!flag[i])
		{
			prime.push_back(i);
			for(int j = i+i; j < 1125; j += i)
				flag[j] = 1;
		}
	}
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	build();

	//初始狀態: 和要是0,用0個prime組成,所以有一種方法
	//轉移狀態: 確定要選這個prime[k]質數，挪出空間考慮Prime[k]的方法數，與沒選Prime[k]的方法數
	// k 枚舉Prime, 有2, 有2,3, 有2,3,5....
	// i 從最大總和往回推
	// j 枚舉現在選了幾個數

	for(int k = 0; k < prime.size(); k++)
	{
		for(int i = 1124; i >= prime[k]; i--)
		{
			for(int j = 1; j < 15; j++)
			{
				dp[i][j] += dp[i-prime[k]][j-1];
			}
		}
	}

	int n,k;
	while(cin >> n >> k)
	{
		if(!n && !k)
			break;
		else
		{
			printf("%d\n",dp[n][k]);
		}
	}

	return 0;
}