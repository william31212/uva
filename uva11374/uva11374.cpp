#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "uva11374"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define E 1000
#define INF 1e9
#define PB push_back
#define MP make_pair 
typedef pair<int,int> P;//to,wei

vector <P> e[E];
int dis_from[E];
int parent_from[E];
int dis[E];
int parent[E];
int dis_to[E];
int parent_to[E];
bool visit[E];
int shortest = INF;
int sta;
int beginn,endd;

void build(int from,int to,int len)
{
	e[from].PB(MP(to,len));
	e[to].PB(MP(from,len));

}

void del(int from,int to)
{
	e[from].pop_back();
	e[to].pop_back();
}


void dijkstra(int src,int point)
{

	int wei,cur,to;

	for (int i = 1; i <= point; ++i)
	{
		dis[i] = INF;
	}
	memset(parent,0,sizeof(parent));
	memset(visit,0,sizeof(visit));

	priority_queue<P,vector<P>,greater<P>> pq;

	parent[src] = src;

	dis[src] = 0;
	pq.emplace(0,src);//wei,point

	while(!pq.empty())
	{
		tie(wei,cur) = pq.top();
		pq.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;


		for(auto i : e[cur])
		{
			tie(to,wei) = i;

			if (dis[to] > dis[cur] + wei)
			{
				dis[to] = dis[cur] + wei;
				parent[to] = cur;
				pq.emplace(dis[to],to);

			}
		}
 		
	}
}

void print_begin(int start)
{
	if (start == beginn)
	{
		printf("%d",beginn );
		return;
	}

	print_begin(parent_from[start]);
	printf(" %d",start);
	
}

void print_endd(int terminal)
{
	if (endd == terminal)
	{
		printf(" %d\n",endd);
		return;
	}

	printf(" %d",terminal);
	print_endd(parent_to[terminal]);
	
	
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	
	int kase = 0;

	while(~scanf("%d %d %d",&sta,&beginn,&endd))
	{
		if (kase++)
			printf("\n");

		int normal,from,to,len;

		scanf("%d",&normal);
		for (int i = 0; i < normal; ++i)
		{
			scanf("%d %d %d",&from,&to,&len);
			build(from,to,len);
		}
		
	
		dijkstra(beginn,sta);
		memcpy(dis_from,dis,sizeof(dis_from));
		memcpy(parent_from,parent,sizeof(parent_from));

		
		dijkstra(endd,sta);
		memcpy(dis_to,dis,sizeof(dis_to));
		memcpy(parent_to,parent,sizeof(parent_to));

	

		int ans = dis_from[endd], sto = -1, tto = -1;
		
		int exp;

		scanf("%d",&exp);//has-exp

		for (int i = 0; i < exp; ++i)
		{
			scanf("%d %d %d",&from,&to,&len);
			build(from,to,len);

			if (dis_from[from] + len + dis_to[to] < ans)
			{
				ans = dis_from[from] + len + dis_to[to];
				sto = from;
				tto = to;
			}
			if (dis_from[to] + len + dis_to[from] < ans)
			{
				ans = dis_from[to] + len + dis_to[from];
				sto = to;
				tto = from;
			}
			del(from,to);
			
		}

		if (sto == -1)
		{
			print_begin(endd);
            printf("\n");
            printf("Ticket Not Used\n");
		}
		else
		{
			print_begin(sto);
            print_endd(tto);
            printf("%d\n", sto);
		}
		printf("%d\n",ans );

		//clear
		for (int i = 0; i <= sta; ++i)
		{
			e[i].clear();
		}

	}



	return 0;
}