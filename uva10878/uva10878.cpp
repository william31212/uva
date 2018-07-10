#include <iostream>
#include <cstdio>
#include <cmath>

//嘗試只用C寫，不使用getline,但是uva似乎不給用gets，只好用fgets
using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10878.in","r",stdin);
	freopen("uva10878.out","w",stdout);
	#endif

	char input[13];
	int in[8] = {0};
	int flag = 0;

	while(1)
	{	
		fgets(input,13,stdin);
		int k = 0;
		for (int i = 0; i < 11; ++i)
		{
			if (input[i] == 'o')
			{
				in[k] = 1;
				k++;
			}
			if (input[i] == ' ')
			{
				in[k] = 0;
				k++;
			}
		}
		
		if (input[0] == '_' && flag)
		{
			break;
		}

		if (flag)
		{
			int sum = 0;
			for (int i = 7; i >= 0 ; --i)
			{
				sum += in[i] * pow(2.0,7-i);
			}
			printf("%c",sum);
		}

		if(input[0] == '_')
		{
			flag = 1;
		}
	}

	return 0;
}
	