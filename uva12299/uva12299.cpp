#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva12299"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 100000

int *tree = new int[4*MAXN+5];
int *A = new int[MAXN+5];
int ans = MAXN;

void clear()
{
	ans = MAXN;
}

void build(int vertex, int L, int R)
{
	if (L == R)
	{
		tree[vertex] = A[L];
		return;
	}
	else
	{
		int nL = vertex*2;
		int nR = vertex*2+1;

		build(nL, L, (L+R)/2);
		build(nR, (L+R)/2+1, R);

		tree[vertex] = min(tree[nL], tree[nR]);
	}
}

void query(int vertex, int L, int R, int ql, int qr)
{
	if(R < ql || L > qr)
		return;
	else if(ql <= L && R <= qr)
	{
		ans = min(tree[vertex], ans);
	}
	else
	{
		int nL = vertex*2;
		int nR = vertex*2+1;
		query(nL, L, (L+R)/2, ql, qr);
		query(nR, (L+R)/2+1, R, ql, qr);
	}
}

void update(int vertex, int L, int R, int index, int val)
{
	if(L == R && index == L)
	{
		tree[vertex] = val;
		return;
	}
	else
	{
		int mid = (L+R)/2;
		if (mid < index)
			update(2*vertex+1, mid+1, R, index, val);
		else
			update(2*vertex, L, mid, index, val);
		//曾經錯在這
		tree[vertex] = min(tree[2*vertex], tree[2*vertex+1]);
	}
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int len,times;


	scanf("%d %d",&len,&times);

	for (int i = 0; i < len; ++i)
	{
		scanf("%d",&A[i]);
	}

	build(1,0,len-1);

	string str;
	while(times--)
	{
		cin >> str;
		vector <int> pos;
		pos.clear();
		int idx = 0;

		if (str[0] == 'q')
		{
			int tmp = 0;
			clear();
			for (int i = 6; i < str.size(); ++i)
			{
				if (isdigit(str[i]))
				{
					tmp = tmp * 10 + str[i] - '0';
				}
				else
				{
					tmp -= 1;
					pos.push_back(tmp);
					tmp = 0;
				}
			}
			query(1, 0, len-1, pos[0], pos[1]);
			printf("%d\n",ans);
		}

		else if (str[0] == 's')
		{
			int tmp = 0;
			for (int i = 6; i < str.size(); ++i)
			{
				if (isdigit(str[i]))
				{
					tmp = tmp * 10 + str[i] - '0';
				}
				else
				{
					tmp -= 1;
					pos.push_back(tmp);
					tmp = 0;
				}
			}

			sort(pos.begin(),pos.end());

			int head = A[pos[0]];
			for (int i = 0; i < pos.size(); ++i)
			{
				if (i == pos.size()-1)
				{
					A[pos[i]] = head;
				}
				else
				{
					A[pos[i]] = A[pos[i+1]];
				}
				update(1, 0, len-1, pos[i], A[pos[i]]);
			}

		}
	}


	return 0;
}