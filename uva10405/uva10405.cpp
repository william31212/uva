#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10405"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define LEN 1005

string s1;
string s2;
int length[LEN + 5][LEN + 5];
int lcs[LEN];

void LCS(int n1,int n2,string s1,string s2)
{

    for (int i = 0; i <= n1; i++)
    	length[i][0] = 0;
    for (int j = 0; j <= n2; j++)
    	length[0][j] = 0;

	for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++)
            if (s1[i-1] == s2[j-1])
            {
                length[i][j] = length[i-1][j-1] + 1;
            }
            else
            {
                length[i][j] = max(length[i][j-1],length[i-1][j]);
            }
    cout << length[n1][n2]  << '\n';

}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif


	while(getline(cin,s1))
	{
		getline(cin,s2);
		if (s1.size() > s2.size())
		{
			LCS(s1.size(),s2.size(),s1.c_str(),s2.c_str());
		}
		else
		{
			LCS(s2.size(),s1.size(),s2.c_str(),s1.c_str());
		}


	}

	return 0;
}