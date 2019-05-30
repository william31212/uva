#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10221"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	double pi = 3.14159265358979323846;

	double s;
	int a;
	string str;
	double du = pi/180;
	double minn = pi/10800;

	while(cin >> s >> a >> str)
	{
		if (str[0] == 'd')
		{
			a = a % 360;
			double ans2 = (s + 6440) * sin(a / 2 * du) * 2;
			double ans = 2 * (s + 6440) * pi * (a / (double)360);
			double len = 2 * (s + 6440) * pi;
			if (a > 180)
				ans = len - ans;

			printf("%.6f %.6f\n",ans, ans2);
		}
		else if (str[0] == 'm')
		{
			a = a % 21600;
			double ans4 = (s + 6440) * sin(a / 2 * minn) * 2;
			double ans3 = 2 * (s + 6440) * pi * (a / (double)21600);
			double len = 2 * (s + 6440) * pi;
			if(a > 10800)
				ans3 = len - ans3;
			printf("%.6f %.6f\n", ans3, ans4);
		}
		
		
		
	}

	return 0;
}