#include <iostream>

using namespace std;

int f(int input)
{
	int sum = 0;
	while(input > 0)
	{
		sum += input%10;
		input/=10;
	}
	input = sum;

	if(input > 9)
	{
		f(input);
	}
	else
	{
		return input;
	}
}


int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11332.in","r",stdin);
	freopen("uva11332.out","w",stdout);
	#endif

	int num;

	while(scanf("%d",&num) != EOF && num)
	{
		printf("%d\n",f(num));
	}

	return 0;
}
	