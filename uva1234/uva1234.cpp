#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva1234"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define E 200000

int fr,to,wei;
int point,len;
int times;
int ds[E];
bool valid[E];


struct edge
{
	int from,to,dis;
	bool operator < (const edge &rhs) const
	{ 
		return dis > rhs.dis; 
	}

};

vector <edge> e;


void init()
{
	for (int i = 1; i <= point; ++i)
	{
		ds[i] = i;
	}
}

int find(int i)	
{
	return ds[i] == i ? i : find(ds[i]);
}

void uni(int a,int b)
{
	ds[find(a)] = find(b);//a祖先的位置改成b祖先
}

void kruskal(int vertex,int edg)
{
	init();
	sort(&e[0],&e[edg]);

	memset(valid,true,sizeof(valid));

	int total = 0;
	int i = 0,j = 0;
	for ( i = 0 ,j = 0; i < vertex - 1 &&  j < edg ; i++ ,j++ )//n-1條邊，with枚舉幾條
	{
		while(find(e[j].from) == find(e[j].to))//相同會留下不變成false
			j++;

		uni(e[j].from,e[j].to);
		valid[j] = false;
	}

}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	while(scanf("%d",&times) && times)
	{

		while(times--)
		{
			scanf("%d %d",&point,&len);

			edge tmp;
			for (int i = 0; i < len; ++i)
			{
				scanf("%d %d %d",&tmp.from,&tmp.to,&tmp.dis);
				e.push_back(tmp);
			}

			kruskal(point,len);

			int camera = 0;

			for(int i = 0; i < len; i++)
			{
				if(valid[i])	
					camera += e[i].dis;
			}
				
			printf("%d\n",camera);
			e.clear();
		}
	}



	return 0;
}