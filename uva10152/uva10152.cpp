#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10152"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

vector <string> bef,aft;

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t,len;
	bool flag = 0;
	scanf("%d\n",&t);

	while(t--)
	{
		scanf("%d\n",&len);
		string tmp;
		bef.clear(),aft.clear();

		for (int i = 0; i < len; i++)
			getline(cin,tmp), bef.PB(tmp);

		for(int j = 0; j < len; j++)
			getline(cin,tmp), aft.PB(tmp);

		int ans = 0;
		for(int i = len-1, j = len-1; i >= 0 and j >= 0;)
		{
			if(bef[i] == aft[j])
				i--, j--,ans = j;
			else
				i--,ans = j;
		}
		if(!flag)
			flag = 1;
		else
			printf("\n");
		for(int i = ans; i >= 0; i--)
			cout << aft[i] << '\n';
	}
	cout << '\n';


	return 0;
}