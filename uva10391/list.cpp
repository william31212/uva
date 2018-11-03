#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "list"
#define N 120000
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

string str[N+10];
vector<string>node[N];
vector<string>::iterator iter;

void add(unsigned int num, string str)
{
	node[num].push_back(str);
}

size_t BKDRHash(const char str[])
{
	size_t seed = 31;
	size_t hash = 0;

	while(*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF) % 10000;
}

bool canfind(string str)
{
	unsigned int index = BKDRHash(str.c_str());
	for(iter = node[index].begin() ; iter != node[index].end(); iter++)
	{
		if (*iter == str)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int n = 0;

	while(cin >> str[n])
	{
		unsigned int index = BKDRHash(str[n].c_str());
		add(index,str[n]);
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