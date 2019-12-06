#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva108"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 500
#define REP(x, y, z) for (int x = y; x <= z; x++)

int arr[MAXN][MAXN];
int prefix[MAXN][MAXN];
int dp[MAXN][MAXN];
int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int n;
	while (cin >> n)
	{
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		REP(i, 1, n)
		REP(j, 1, n)
		{
			scanf("%d", &arr[i][j]);
		}

		REP(i, 1, n)
		REP(j, 1, n)
		{
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}

		int ans = INT_MIN;
		REP(i, 1, n)REP(j, 1, n) REP(k, i, n) REP(l, j, n)
		{
			int tmp = arr[k][l] - arr[k][j - 1] - arr[i - 1][l] + arr[i - 1][j - 1];
			ans = max(tmp, ans);
		}
		cout << ans << '\n';
	}

	return 0;
}
