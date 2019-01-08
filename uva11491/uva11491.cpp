#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11491"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define mp make_pair<int,int>

const int maxn = 100005;
int str[maxn];


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int n, d;
	while (scanf("%d %d\n", &n, &d) && n && d) {
		int t = 0;
		int a;
		d = n - d;
		for (int i = 0; i < n; i++)
		{
			a = getchar() - '0';
			while (t && t + (n - i) > d && a > str[t - 1])
			{
				t--;
			}
			if (t < d) {
				str[t++] = a;
			}
		}
		for (int i = 0; i < t; i++)
		{
			printf("%d", s[i]);
		}
		printf("\n");
	}
 
	return 0;
}
