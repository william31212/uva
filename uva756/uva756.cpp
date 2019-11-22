#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva756"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define LL long long

vector<LL> m, a;

LL Euler(LL n)
{
	LL ans = n;
	for (LL i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}
LL pow_mod(LL n, LL k, LL m)
{
	LL ans = 1;
	for (n = (n >= m ? n % m : n); k; k >>= 1)
	{
		if (k & 1)
			ans = ans * n % m;
		n = n * n % m;
	}
	return ans;
}
LL CRT()
{
	LL M = 1, tM, ans = 0;
	for (int i = 0; i < m.size(); ++i)
		M *= m[i];
	for (int i = 0; i < a.size(); ++i)
	{
		tM = M / m[i];
		//ans = a(模完結果)*M*t(M的逆元), t用費馬小求,
		ans = (ans + (a[i] * tM % M) * pow_mod(tM, Euler(m[i]) - 1, m[i]) % M) % M;
	}
	return ans;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	LL aa=0,bb=0,cc=0,dd=0;
	int kase = 1;
	while (cin >> aa >> bb >> cc >> dd)
	{
		m.clear(),a.clear();
		if(aa == -1 && bb == -1 && cc == -1 && dd == -1)
			break;
		m.PB(23),m.PB(28),m.PB(33);
		a.PB(aa),a.PB(bb),a.PB(cc);

		LL ans = CRT();
		ans = ans-dd;
		if(ans == 0)
			printf("Case %d: the next triple peak occurs in 21252 days.\n", kase++);
		else if(ans < 0)
		{
			while(ans < 0)
				ans += 21252;
			printf("Case %d: the next triple peak occurs in %lld days.\n",kase++, ans);
		}
		else
		{
			printf("Case %d: the next triple peak occurs in %lld days.\n", kase++, ans);
		}
	}
	return 0;
}