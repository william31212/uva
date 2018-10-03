#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	#endif

	bool flag[33000];
	fill(flag , flag+33000 , 1);
	flag[0] = 0;
	flag[1] = 0;
	for(int i = 2; i <= 33000; i++)
	{
		if(flag[i] == 1)
		{
			for(int j = i * i; j <= 33000 ; j += i)
			{
				flag[j] = 0;
			}
		}
	}
	int num = 0;
	int times = 0;
	while(cin >> num)
	{
		if(num == 0)
		{
			break;
		}
		else if(flag[num/2] == 1)
		{
			times++;
		}
		for(int i = 1; i < num/2 ; i++)
		{
			if(flag[(num/2) - i] == 0 && flag[(num/2) + i] == 0)
			{
				continue;
			}
			else if(flag[(num/2) - i] == 1 && flag[(num/2) + i] == 1)
			{
				times++;
			}
		}

		cout << times << endl;
		times = 0;
	}
	return 0;
}
