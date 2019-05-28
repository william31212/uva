#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11220"
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

	int times;
	int cases = 1;
	string str;
	scanf("%d\n\n",&times);

	bool flag = 0;

	while(times--)
	{
		if(!flag)
		{
			printf("Case #%d:\n", cases++);
			flag = 1;
		}
		else
		{
			printf("\nCase #%d:\n", cases++);
		}

		while(getline(cin,str))
		{
			if(str.size() == 0)
			{
				break;
			}
			vector<string> vec;
			
			int tmp = 0;
			while(str[tmp] == ' ')
			{
				tmp++;
			}
			for(int i = tmp; i < str.size(); i++)
			{	
				string want = "";

				if(i == str.size()-1)
				{
					for (int j = tmp; j < str.size(); j++)
					{
						want += str[j];
					}
					vec.push_back(want);
				}
				else if(str[i] == ' ')
				{	
					for(int j = tmp; j < i; j++)
					{
						want += str[j];
					}
					vec.push_back(want);

					while(str[i] == ' ')
					{
						i++;
					}
					tmp = i;
				}
			}	
			int idx = 0;
			for(int k = 0; k < vec.size(); k++)
			{
				if(vec[k].size() - 1 < idx)
					continue;
				else
				{
					cout << vec[k][idx];
					idx++;
				}
			}
			cout << '\n';
		}
	}

	return 0;
}