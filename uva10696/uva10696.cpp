#include <iostream>
#include <cstdio>
using namespace std;

int f91(int num){
	if(num >= 101){
		num-=10;
		return num;
	}
	else{
		return f91(f91(num + 11));
	}
}


int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10696.in","r",stdin);
	freopen("uva10696.out","w",stdout);
	#endif
	int N = 0;

	while(scanf("%d",&N) != EOF){
		if(N == 0){
			break;
		}
		printf("f91(%d) = %d\n",N,f91(N));
	}
	return 0;
}
	