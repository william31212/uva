#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva103"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int B, dim = 0;

struct Box
{
	int num;
	int edge[10];

	friend bool operator < (const Box &lhs, const Box &rhs)
	{
		bool flag = 0;
		for (int i = 0; i < dim; i++)
		{
			if (lhs.edge[i] >= rhs.edge[i])
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			return true;
		else
			return false;
	}
};


//按照字典序排序
bool cmp(const Box &lhs, const Box &rhs)
{
	for (int i = 0; i < dim; i++)
	{
		if ( lhs.edge[i] <= rhs.edge[i] )
			return true;
		else
			return false;
	}
	
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	while(~scanf("%d %d",&B,&dim))
	{
		Box box[35];
		int dp[35];
		int state[35];
		for(int i = 0; i < 35; i++)
			dp[i] = 1;
		memset(state,-1,sizeof(state));


		for(int i = 1; i <= B; i++)
		{
			box[i].num = i;
			for (int j = 0; j < dim ; j++)
				scanf("%d", &box[i].edge[j]);	
		}

		//邊排序
		for (int i = 1; i <= B; i++)
			sort(box[i].edge, box[i].edge+dim);
		
		//字典序排序
		sort(box+1, box+B+1, cmp);

		//LIS
		for(int i = 1; i <= B; i++)
		{
			for(int j = i+1; j <= B; j++)
			{
				if (box[i] < box[j])
				{
					if(dp[i] + 1 > dp[j])
					{
						dp[j] = dp[i] + 1;
						state[j] = i;
					}
				}
			}
		}

		//LIS-find big
		int n = 0, pos = 0;
		for(int i = 1; i <= B; i++)
		{
			if (dp[i] > n)
			{
				n = dp[i];
				pos = i;
			}
		}

		//len
		cout << n << '\n';

		
		stack <int> stk;
		int iter = pos;
		stk.push(box[iter].num);
		while(state[iter] != -1)
		{
			stk.push(box[state[iter]].num);
			iter = state[iter];
		}
		while(!stk.empty())
		{
			if (stk.size() == 1)
				cout << stk.top();
			else
				cout << stk.top() << " ";
			stk.pop();
		}
		cout << '\n';
	}
	return 0;
}