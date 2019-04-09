#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11747"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

struct Edge
{
    int from;
    int to;
    int len;
    bool operator < (const Edge &rhs) const{
        return len < rhs.len;
    }
};

int MST[1000];

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

    int n, m;
    while (scanf("%d%d", &n, &m))
    {
        if (!m && !n)
            break;

        int from,to,len;
        vector <Edge> e;
        vector <int> ans;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &from, &to, &len);
            e.push_back((Edge){from,to,len});
        }

        sort(&e[0],&e[m]);

        for (int i = 0; i < 1000; i++)
        {
            MST[i] = i;
        }


        for (int i = 0; i < m; ++i)
        {
            int one = e[i].from;
            int two = e[i].to;

            while( MST[one] != one)
                one = MST[one];
            while( MST[two] != two)
                two = MST[two];

            if (one == two)
                ans.push_back(e[i].len);
            else
                MST[two] = one;
        }

        if (ans.empty())
            printf("forest\n");
        else
        {
            printf("%d", ans[0]);
            for (int i = 1; i < ans.size(); i++)
                printf(" %d",ans[i]);
            printf("\n");
        }

    }
    return 0;
}