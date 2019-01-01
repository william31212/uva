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

int find(int i)
{
	return dj[i] == i ? i : find(dj[i]);
}

void uni(int a,int b)
{
	dj[find(a)] = find(b);
}

void kruskal(int vertex,int edg)
{
	init();
	sort(&vec[0],&vec[edg]);

	memset(choseit,0,sizeof(choseit));

	int i,j; 
	for ( i = 0 , j = 0 ; i < vertex - 1 && j < edg ; ++i,++j)
	{
		while(find(vec[j].from) == find(vec[j].to))//產生環的跳過
			j++;

		uni(vec[j].to,vec[j].from);
		choseit[j] = 1;
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

		kruskal(point,vec.size());

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