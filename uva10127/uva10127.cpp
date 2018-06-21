#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n=0;
	
	while(scanf("%d",&n)!=EOF){	
		int tmp=1;
	 	int ans=1;
		while(tmp % n != 0){
			tmp = tmp % n;
			tmp = tmp*10 + 1;
			ans++;
		}
		printf("%d\n",ans);
	}

}