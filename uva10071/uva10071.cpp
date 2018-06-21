#include <iostream>
using namespace std;
int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10071.in","r",stdin);
	freopen("uva10071.out","w",stdout);
	#endif
	int v=0,t=0;
	while(cin >> v >> t){
		cout << (2 * v) * (2 * t) / 2 << endl;
	}
	return 0;
}