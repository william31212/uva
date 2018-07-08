#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10673.in","r",stdin);
	freopen("uva10673.out","w",stdout);
	#endif
	int times;
	cin >> times;
	while(times--){
		long long x,k;
		int a,b;
		cin >> x >> k;
		a = floor((double)x/(double)k);
		b = ceil((double)x/(double)k);
		for(int i=0;;i++){
			if((x - a*i)%b==0){
				cout << i << " " <<(x - a*i)/b << endl;
				break;
			}
		}
	}
	

	return 0;
}