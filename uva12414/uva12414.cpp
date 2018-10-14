#include <bits/stdc++.h>

using namespace std;

int digit[10];
int num[1000];


int fen(string str,int st)
{
	memset(digit,0,sizeof(digit));
	int tmp;
	int rec
	for (int i = 0; i < str.length(); ++i)
	{
		tmp = str[i] - 'A' + st;
		int add = 1;
		while(tmp > 0)
		{
			num[a] = tmp % 10 * add;
			add
		}
	}

	
}


int main(void){

	#ifndef ONLINE_JUDGE
	freopen("uva12414.in","r",stdin);
	freopen("uva12414.out","w",stdout);
	#endif

	cout << "fuck" << endl;

	string str;

	cin >> str;

	for (int st = 0; st <= 10000; ++st)
	{
		fen(str,st);
	}
	

	return 0;
}
	