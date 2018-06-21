#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10055.in","r",stdin);
	freopen("uva10055.out","w",stdout);
	#endif
	long long int a=0,b=0;

	while(cin >> a >> b){
		if(a-b<0){
			cout << 0-(a-b) << endl;
		}
		else{
			cout << a-b << endl;
		}
	}
	

	return 0;
}