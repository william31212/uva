#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva109"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 1000

struct point
{
	int x,y;
};

struct kindom
{
	vector<point> house;
	vector<point> mykin;
	bool bomb = false;
};

int dist(point a, point b)
{
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

int cross(point p1, point p2, point p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool min_y(point a, point b)
{
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

point base;
bool c_clockwise(point a, point b)
{
	int c = cross(base, a, b);
	return c > 0 || (c == 0 && dist(base, a) < dist(base, b));
}


void convex_hull(kindom &kin)
{
	//最左下角點開始
	swap(kin.house[0],*min_element(kin.house.begin(), kin.house.end(), min_y));

	base = kin.house[0];
	sort(kin.house.begin()+1, kin.house.end(), c_clockwise);
	//把原先的點在塞回做結尾判斷
	kin.house.PB(base);


	//枚舉，把外積負的人淘汰
	int m = 0;
	for(int i = 0; i < kin.house.size(); i++)
	{
		//stack的上面兩個與該點做嘗試
		while (m >= 2 && cross(kin.mykin[m-2], kin.mykin[m-1], kin.house[i]) <= 0)
		{
			kin.mykin.pop_back();
			m--;
		}
		kin.mykin.PB(kin.house[i]);
		m++;
	}
}

bool attacked(point bullet, kindom kin)
{
	for(int i = 1; i < kin.mykin.size(); i++)
	{
		if (cross(kin.mykin[i-1], kin.mykin[i], bullet) < 0)
			return false;	
	}
	return true;
}

double area(kindom kin)
{
	// for (int i = 0; i < kin.mykin.size(); i++)
	// 	cout << kin.mykin[i].x << " " << kin.mykin[i].y << '\n';

	double a = 0;
	for (int i = 1; i < kin.mykin.size(); i++)
		a += (kin.mykin[i-1].x * kin.mykin[i].y) - (kin.mykin[i].x * kin.mykin[i-1].y);

	a += (kin.mykin[kin.mykin.size()-1].x * kin.mykin[0].y) - (kin.mykin[0].x * kin.mykin[kin.mykin.size()-1].y);

	return a/2;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int p;
	kindom K[MAXN];
	int idx = 0;

	while(scanf("%d",&p) && p >= 0)
	{
		int x,y;
		for(int i = 0; i < p; i++)
		{
			scanf("%d %d\n", &x, &y);
			K[idx].house.PB({x,y});	
		}
		idx++;
	}

	for(int i = 0; i < idx; i++)
		convex_hull(K[i]);

	// 子彈發射
	point bullet;
	double ans = 0;
	while(~scanf("%d %d\n",&bullet.x, &bullet.y))
	{
		for (int i = 0; i < idx; i++)
		{
			if (attacked(bullet, K[i]) && !K[i].bomb)
			{
				ans += area(K[i]);
				K[i].bomb = true;
			}
				
				
		}
	}
	
	printf("%.2lf\n",ans);
	return 0;
}