#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11192.in","r",stdin);
	freopen("uva11192.out","w",stdout);
	#endif


	int times = 0;
	while(scanf("%d",&times) && times)
	{
		char str[110];
		int word;

		scanf("%s",str);
		word = strlen(str)/times;

		for (unsigned int i = 0; i < strlen(str); i+=word)
		{
			reverse(str+i,str+i+word);
		}

		printf("%s\n",str);
	}
	return 0;
}
	