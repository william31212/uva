#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva10256"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

struct point
{
	int x, y;
};

struct kindom
{
	vector<point> all;
	vector<point> checked;
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
	if (a.y == b.y)
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
	swap(kin.all[0], *min_element(kin.all.begin(), kin.all.end(), min_y));

	base = kin.all[0];
	sort(kin.all.begin() + 1, kin.all.end(), c_clockwise);
	//把原先的點在塞回做結尾判斷
	kin.all.PB(base);

	//枚舉，把外積負的人淘汰
	int m = 0;
	for (int i = 0; i < kin.all.size(); i++)
	{
		//stack的上面兩個與該點做嘗試
		while (m >= 2 && cross(kin.checked[m - 2], kin.checked[m - 1], kin.all[i]) <= 0)
		{
			kin.checked.pop_back();
			m--;
		}
		kin.checked.PB(kin.all[i]);
		m++;
	}
}

bool isinside(point bullet, kindom kin)
{
	for (int i = 1; i < kin.checked.size(); i++)
	{
		if (cross(kin.checked[i - 1], kin.checked[i], bullet) < 0)
			return false;
	}
	return true;
}

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int a,b;
	while(~scanf("%d %d",&a,&b) && a && b)
	{
		int x, y;
		kindom K;
		for(int i = 0; i < a; i++)
		{
			scanf("%d %d", &x, &y);
			K.all.PB({x,y});
		}
		convex_hull(K);
		
		bool flag = 0;
		for(int i = 0; i < b; i++)
		{
			scanf("%d %d",&x,&y);
			if (isinside({x,y}, K))
			{
				cout << "No" << '\n';
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout << "Yes" << '\n';
		
	}


	return 0;
}