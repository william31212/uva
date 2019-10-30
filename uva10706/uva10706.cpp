#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva10706"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	string str;
	int len[35005];
	memset(len,0,sizeof(len));

	for(int i = 1; i <= 35000; i++)
	{
		str += to_string(i);
		len[i] += str.size();
	}

	//cout << str << '\n';
	int t, num;
	cin >> t;
	while(t--)
	{
		cin >> num;
		for(int i = 1; i <= 35000; i++)
		{
			if(num > len[i])
			{
				num -= len[i];
			}
			else
			{
				//printf("%d\n",num);
				printf("%c\n",str[num-1]);
				break;
			}
		}
	}


	return 0;
}