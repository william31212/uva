#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva908"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define E 200000


struct edge
{
	int from,to,dis;
	bool operator < (const edge &rhs) const
	{ 
		return dis < rhs.dis; 
	}
};

vector <edge> vec;
int dj[E];
bool choseit[E];

void init()
{
	for (int i = 1; i <= E-1; ++i)
	{
		dj[i] = i;
	}

}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int point;
	bool flag = 0;


	while(~scanf("%d",&point))
	{

		int src = 0;

		int a,b,c;
		for (int i = 0; i < point-1; ++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			src += c;
		}
		
		int newline;
		scanf("%d",&newline);

		for (int i = 0; i < newline; ++i)
		{
			edge tmp;
			scanf("%d %d %d",&tmp.from,&tmp.to,&tmp.dis);
			vec.push_back(tmp);
		}

		int originline;
		scanf("%d",&originline);

		for (int i = 0; i < originline; ++i)
		{
			edge tmp;
			scanf("%d %d %d",&tmp.from,&tmp.to,&tmp.dis);
			vec.push_back(tmp);
		}

		sort(&vec[0],&vec[vec.size()]);

		
		init();

		memset(choseit,1,sizeof(choseit));
		for (int i = 0; i < vec.size(); ++i)
		{
			int a = vec[i].from;
			int b = vec[i].to;

			while(dj[a] != a)//換成老爸模式
				a = dj[a];

			while(dj[b] != b)//換成老爸模式
				b = dj[b];

			if (a == b)//相同老爸代表是環，這條不能選
			{
				choseit[i] = 0;
			}
			else//這條可以選，b老爸換成a
			{
				dj[b] = a;
			}
		}

		int total = 0;
		for (int i = 0; i < vec.size(); ++i)
		{
			if (choseit[i])
			{
				total += vec[i].dis;
			}
		}

		
		if (!flag)
		{
			printf("%d\n%d\n",src,total);
			flag = 1;
		}
		else
			printf("\n%d\n%d\n",src,total);
		
		vec.clear();
	}


	return 0;
}