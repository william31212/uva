#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva1612"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, double> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

struct node
{
	int arr[8];
}vec[20000];


double a, b, c;
int seq[20000], pre_id = 0;
int t, kase = 1;
int pre = 0;

void init()
{
	memset(vec,0,sizeof(vec));
	memset(seq,0,sizeof(seq));
}

int check(int id, int pre, int pre_id)
{

	if (pre_id > id) // 第一次:3 > 第二次:2
	{
		for (int i = 7; i >= 0; i--)
		{
			if (pre > vec[id].arr[i])
			{
				return i;
			}
		}
		return -1;
	}
	else//第一次:1,第二次:2
	{
		for (int i = 7; i >= 0; i--)
		{
			if (pre >= vec[id].arr[i])
			{
				return i;
			}	
		}
		return -1;
	}
	
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	while(cin >> t && t)
	{		
		init();
		for (int i = 0; i < t; i++)
		{
			cin >> a >> b >> c;

			node no;
			no.arr[0] = 0;
			no.arr[1] = round(a*100);
			no.arr[2] = round(b*100);
			no.arr[3] = round(c*100);
			no.arr[4] = round((a + b)*100);
			no.arr[5] = round((b + c)*100);
			no.arr[6] = round((a + c)*100);
			no.arr[7] = round((a + b + c)*100);
			vec[i+1] = no;
		}

		for(int i = 0; i < t; i++)
			cin >> seq[i];


		bool success = 1;
		for(int i = 0; i < t ; i++)
		{
			sort(vec[seq[i]].arr,vec[seq[i]].arr+8);
			if(i == 0)
			{
				pre = vec[seq[i]].arr[7];
				pre_id = seq[i];
			}
			else
			{
				int state = check(seq[i], pre, pre_id);
				if (state >= 0)
				{
					pre = vec[seq[i]].arr[state];
					pre_id = seq[i];
				}
				else
				{
					success = 0;
					break;
				}	
			}
		}

		if(!success)
			printf("Case %d: No solution\n",kase++);
		else
			printf("Case %d: %.2f\n",kase++,pre/100.00);
	}
	return 0;
}