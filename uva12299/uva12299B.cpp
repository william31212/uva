#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva12299B"
#define USE_CPPIO()               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAXN 100005

int A[MAXN];
int tree[4*MAXN];
int ans = INF;

void build(int vertex, int L, int R)
{
    if(L == R)
    {
        tree[vertex] = A[L];
        return;
    }
    else
    {
        build(vertex * 2, L, (L + R) / 2);
        build(vertex * 2 + 1, (L + R) / 2 + 1, R);
        tree[vertex] = min(tree[vertex * 2], tree[vertex * 2 + 1]);
    }
    
   
}

void query(int vertex, int L, int R, int ql, int qr)
{
    if(ql > R || qr < L)
        return;
    else if (ql <= L && R <= qr)
    {
        ans = min(tree[vertex], ans);
    }
    else
    {
        query(vertex*2, L, (L+R)/2, ql, qr);
        query(vertex*2+1, (L+R)/2+1, R, ql, qr);
    }
    

    
}

void update(int vertex, int L, int R, int idx, int val)
{
    if(L == R && idx == L)
    {
        tree[vertex] = val;
        return;
    }
    else
    {
        int mid = (L+R)/2;
        if(mid >= idx)
            update(vertex*2,L,mid,idx,val);
        else
            update(vertex*2+1,mid+1,R,idx,val);

        tree[vertex] = min(tree[vertex*2],tree[vertex*2+1]);
    }
    
}


int main()
{
    #ifdef DBG
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    #endif

    int num,que;
    while(~scanf("%d %d",&num,&que))
    {

        memset(A,0,sizeof(A));
        memset(tree,0,sizeof(tree));
        for(int i = 0,tmp = 0; i < num && scanf("%d",&tmp); i++)
            A[i] = tmp;

        build(1,0,num-1);

        for(int ii = 0; ii < que; ii++)
        {
            string str;
            cin >> str;
            if(str[0] == 'q')
            {
                vector <int> vec;
                ans = INF;
                int tmp = 0;
                for(int i = 6; i < str.size(); i++)
                {
                    if(isdigit(str[i]))
                        tmp = tmp * 10 + str[i] - '0';
                    else
                    {
                        vec.PB(tmp-1);
                        tmp = 0;
                    }
                        
                }
                query(1, 0, num - 1, vec[0], vec[1]);
                printf("%d\n", ans);
            }
            else if(str[0] == 's')
            {
                vector<int> vec2;
                int tmp = 0;
                for (int i = 6; i < str.size(); i++)
                {
                    if (isdigit(str[i]))
                        tmp = tmp * 10 + str[i] - '0';
                    else
                    {
                        vec2.PB(tmp-1);
                        tmp = 0;
                    }
                        
                }

                sort(vec2.begin(),vec2.end());
                
                int tmp2 = A[vec2[0]];

                for(int i = 0; i < vec2.size(); i++)
                { 
                    if (i == vec2.size()-1)
                    {
                        A[vec2[i]] = tmp2;
                    }
                    else
                    {
                        A[vec2[i]] = A[vec2[i+1]];
                    }
                    update(1, 0, num - 1, vec2[i], A[vec2[i]]);
                }

                
            }
            
        }
    }

}