#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva531"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int dp[205][205];
int state[205][205];

void LCS(int a_len, int b_len, string a[], string b[])
{
	memset(dp,0,sizeof(dp));
	memset(state, 0, sizeof(state));
	for(int i = 1; i <= a_len; i++)
	{
		for (int j = 1; j <= b_len; j++)
		{
			if(a[i] != b[j])
			{
				if (dp[i-1][j] > dp[i][j-1])
				{
					state[i][j] = 1;
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					state[i][j] = 2;
					dp[i][j] = dp[i][j - 1];
				}
				
			}
			else
			{
				state[i][j] = 3;
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			
		}
	}

}

vector<string> findpath(int a_len, int b_len, string a[], string b[])
{
	int i = a_len;
	int j = b_len;
	vector <string> vec;
	while(i != 0 && j != 0)
	{
		if(state[i][j] == 1)
		{
			i -= 1;
		}
		else if (state[i][j] == 2)
		{
			j -= 1;
		}
		else if (state[i][j] == 3)
		{
			vec.PB(a[i]);
			i -= 1;
			j -= 1;
		}
	}
	return vec;
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	string a[105];
	string b[105];
	int i = 1;
	int j = 1;
	string ans;

	while(cin >> a[i])
	{
		if (a[i] == "#")
		{
			while(cin >> b[j])
			{
				if(b[j] == "#")
				{
					i--;
					j--;
					LCS(i, j, a, b);
					auto ans =  findpath(i, j, a, b);
					reverse(ans.begin(),ans.end());
					for (int it = 0; it < ans.size(); it++)
						printf("%s", it == ans.size()-1 ? (ans[it] + '\n').c_str() : (ans[it] + " ").c_str());
					break;
				}
				j++;
			}

			i = 1;
			j = 1;
			ans = "";
			continue;
		}

		i++;
	}
	return 0;
}