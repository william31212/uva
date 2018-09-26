#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "p5"
#define N 120000
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int head[N+10];
int n,tot;
string str[N+10];

struct list
{
	int data;
	int next;

}arr[N+10];


size_t BKDRHash(const char str[])
{
	size_t seed = 31;
	size_t hash = 0;

	while(*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF) % N;
}

void add(unsigned int index,int m)
{
	arr[tot].data = m;
	arr[tot].next = head[index];
	head[index] = tot++;
}

bool canfind(string str_input)
{
	unsigned int index = BKDRHash(str_input.c_str());
	for (int x = head[index]; x != -1; x = arr[x].next)
	{
		int m = arr[x].data;
		if (!strcmp(str[m].c_str(),str_input.c_str()))
		{
			return 1;
		}
	}
	return 0;
}



int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	n = tot = 0;
	memset(head,-1,sizeof(head));
	
	while(cin >> str[n])
	{
		unsigned int index = BKDRHash(str[n].c_str());
		add(index,n);
		n++;
	}

	for(int i = 0 ; i < n ; i++)
	{
        for(int k = 1 ; k < str[i].length() ; k++)
        {
            string sub1 = str[i].substr(0,k);
            string sub2 = str[i].substr(k,str[i].length()-k);
            if(canfind(sub1)  &&  canfind(sub2))
            {
                cout << str[i] << endl;
                break;
            }
        }
    }


	return 0;
}