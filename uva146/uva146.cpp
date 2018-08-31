#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva146.in","r",stdin);
	freopen("uva146.out","w",stdout);
	#endif

	string str;

	while(getline(cin,str) && str[0] != '#')
	{
		if (next_permutation(str.begin(),str.end()))
		{
			cout << str << endl;
		}
		else
		{
			cout << "No Successor" << "\n";
		}
	}

	return 0;
}
	