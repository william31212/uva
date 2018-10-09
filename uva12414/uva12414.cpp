#include <bits/stdc++.h>

using namespace std;



bool fen(string str,int ST)
{
	int tmp;
	int rec = 0;

	char num[1000];
	char small[50];
	memset(small,0,sizeof(small));
	memset(num,0,sizeof(num));


	for (int i = 0; i < str.length(); ++i)
	{
		tmp = str[i] - 'A' + ST;
		// itoa(tmp,small,10);
		snprintf(small, sizeof(small), "%d", tmp);

		for (int j = 0; j < strlen(small); ++j)
		{
			num[rec] = small[j];
			rec++;
		}
	}
	
	
	int len = strlen(num);
	
	// printf("ST:%d\n", ST);
	while(len >= 3)
	{
		// for (int i = 0; i < len; ++i)
		// {
		// 	printf("%c", num[i]);
		// }
		// printf("\n");
		if (len == 3)
		{
			if (num[0] == '1' && num[1] == '0' && num[2] == '0')
			{
				return true;
			}
		}
		for (int i = 0; i < len - 1; ++i)
		{
			if (num[i] - '0' + num[i+1] - '0' >= 10)
			{
				num[i] = ((num[i] - '0') + (num[i+1] - '0')) % 10 + '0';
			}
			else
			{
				num[i] = (num[i] - '0' + num[i+1] - '0') + '0';
			}
		}
		len--;
	}

	return false;

}






int main()
{
	#ifdef DBG
	freopen("uva12414.in","r",stdin);
	freopen("uva12414.out","w",stdout);
	#endif

	string str;


	while(cin >> str)
	{
		bool flag = 0;

		for (int i = 0; i <= 10000; ++i)
		{
			if (fen(str,i))
			{
				cout << i;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			cout << ":(";
		}
		cout << "\n";
	}
	
	return 0;

}   