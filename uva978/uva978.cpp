#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva978"
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int B,SG,SB;
		scanf("%d %d %d",&B,&SG,&SB);

		vector<int> field;
		multiset<int,greater<int>> green;
		multiset<int,greater<int>> blue;

		int tmp;
		for(int i = 0; i < SG; i++)
		{
			cin >> tmp;
			green.insert(tmp);
		}

		for (int i = 0; i < SB; i++)
		{
			cin >> tmp;
			blue.insert(tmp);
		}

		while(!green.empty() && !blue.empty())
		{
			field.clear();
			for(int i = 0; i < B; i++)
			{
				if(green.empty() || blue.empty())
					break;
				field.PB(*green.begin()-*blue.begin());
				green.erase(green.begin());
				blue.erase(blue.begin());
			}

			for(int iter = 0; iter < field.size(); iter++)
			{
				if(field[iter] > 0)
					green.insert(field[iter]);
				else if(field[iter] < 0)
					blue.insert(-field[iter]);
			}
		}


		if(green.empty() && blue.empty())
			printf("green and blue died\n");
		else if (green.empty())
		{
			printf("blue wins\n");
			while(!blue.empty())
			{
				printf("%d\n",*blue.begin());
				blue.erase(blue.begin());
			}
		}
		else if (blue.empty())
		{
			printf("green wins\n");
			while (!green.empty())
			{
				printf("%d\n", *green.begin());
				green.erase(green.begin());
			}
		}
		if(t)
			printf("\n");
	}


	return 0;
}