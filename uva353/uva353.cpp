#include <bits/stdc++.h>

using namespace std;

bool check_palindromes(string str)
{

	for (int i = 0; i < str.length()/2; ++i)
	{
		if (str[i] != str[str.length() - i - 1])
		{
			return false;
		}	
	}
	return true;
}



int main()
{
	#ifdef DBG
	freopen("uva353.in","r",stdin);
	freopen("uva353.out","w",stdout);
	#endif

	string str;
	

	while(cin >> str)
	{
		map<string, bool> ans;
		int cnt = 0;

		for (int len = str.length(); len >= 1; --len)
		{
			for (int j = 0; j < str.length() ; ++j)
			{
				if ( j + len > str.length())
				{
					break;
				}
				// cout << str.substr(j,len) << '\n';
				string sub;
				sub = str.substr(j,len);

				if (check_palindromes(sub))
				{
					if (cnt == 0)
					{
						cnt++;
						ans[sub] = true;
					}
					if (!ans[sub])
					{
						cnt++;
						ans[sub] = true;
					}
				}
			}
		}

		cout << "The string '"<< str <<"' contains " << cnt << " palindromes." << "\n";
	}
	
	return 0;

}