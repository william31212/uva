#include <bits/stdc++.h>

using namespace std;

#define PROBLEM ""
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

struct node
{
	char a;
	int num;
	bool operator < (const node &r)
	{
		if (num == r.num)
			return a < r.a;
		else
			return num > r.num;
	}
}word[26];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int t;

	//init
	for (int i = 0; i < 26; i++)
	{
		word[i].a = (char)(65 + i);
		word[i].num = 0;
	}
	scanf("%d\n", &t);
	string str;

	while(t--)
	{
		getline(cin, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				word[str[i] - 'a'].num++;
			if (str[i] >= 'A' && str[i] <= 'Z')
				word[str[i] - 'A'].num++;
		}
	}
	sort(word, word+26);

	for (int i = 0; i < 26; i++)
	{
		if (word[i].num == 0)
			continue;
		else
			printf("%c %d\n", word[i].a, word[i].num);
	}
	return 0;
}