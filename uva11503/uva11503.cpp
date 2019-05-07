#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "uva11503"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define MAX_GROUP 200005

int merge(map<string, int> &checkset, vector< set<string> > &sets, std::string friendName, std::string friendName2)
{

	if (checkset.find(friendName) != checkset.end() && checkset.find(friendName2) == checkset.end())//A找不到B找到
	{
		checkset[friendName2] = checkset[friendName];
		sets[ checkset[friendName] ].insert(friendName2);
	}
	else if (checkset.find(friendName) == checkset.end() && checkset.find(friendName2) != checkset.end())//A找到B找不到
	{
		checkset[friendName] = checkset[friendName2];
		sets[ checkset[friendName] ].insert(friendName);
	}

	else if (checkset.find(friendName) == checkset.end() && checkset.find(friendName2) == checkset.end())//兩個都找不到
	{
		int tmp = checkset.size();
		checkset[friendName] = tmp;
		checkset[friendName2] = tmp;
		sets[ checkset[friendName] ].insert(friendName);
		sets[ checkset[friendName] ].insert(friendName2);
	}

	else if (checkset.find(friendName) != checkset.end() && checkset.find(friendName2) != checkset.end())//兩個都找到
	{

		if (checkset[friendName] > checkset[friendName2])//A所在位置idx比較小，因此將B merge到A，B格刪除
		{
			int remove_set = checkset[friendName];
			for( set<string>::iterator it = sets[ remove_set ].begin() ; it != sets[ remove_set ].end() ; ++it )
			{
				checkset[*it] = checkset[friendName2];
				sets[checkset[friendName2]].insert(*it);
			}
			sets[remove_set].clear();
		}
		else if (checkset[friendName] < checkset[friendName2])
		{
			int remove_set = checkset[friendName2];
			for( set<string>::iterator it = sets[ remove_set ].begin() ; it != sets[ remove_set ].end() ; ++it )
			{
				checkset[*it] = checkset[friendName];
				sets[checkset[friendName]].insert(*it);
			}
			sets[remove_set].clear();
		}
	}

	return sets[ checkset[friendName] ].size();

}
int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int times,req;
	cin >> times;
	while(times--)
	{
		map<string, int> checkset;
		vector< set<string> > sets(MAX_GROUP);
		cin >> req;
		for (int i = 0; i < req; i++)
		{
			string name1, name2;
			cin >> name1 >> name2;
			cout << merge(checkset, sets, name1, name2) << '\n';
		}

	}
	return 0;
}