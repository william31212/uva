#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "1617"
#define PB push_back
#define MP make_pair
#define F first
#define S second

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("uva" PROBLEM TESTC ".in", "r", stdin);
	freopen("uva" PROBLEM ".out", "w", stdout);
	#endif

	int times,num;
	vector < pair <int,int> > sch;
	int one,two;
	scanf("%d",&times);
	
	while(times--)
	{
	    scanf("%d",&num);
	    
	    for (int i = 0; i < num; i++)
	    {
	        scanf("%d %d",&one,&two);
	        sch.PB(MP(two,one));
	    }
	    
	    sort(sch.begin(),sch.end());
	    
	    int ans = 0;
	    int tmp = sch[0].F;
	    
	    for(int i = 1 ; i < num ; i++)
	    {
	        if(tmp != sch[i].F)
	            if(tmp < sch[i].S)
	            {
	                ans++;
	                tmp = sch[i].F;
	            }
	        else
	        {
	            tmp++;
	        }
	    }
	    
	    printf("%d\n",ans);
	    sch.clear();
	    
	}

	return 0;
}
