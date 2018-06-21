#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10300.in","r",stdin);
	freopen("uva10300.out","w",stdout);
	#endif
	int times=0,farmer=0;
	while(cin >> times){
		while(cin >> farmer){
			double area[farmer],count[farmer],level[farmer];
			double average=0;
			double money=0;
			for(int i=0;i<farmer;i++){
				cin >> area[i] >> count[i] >> level[i];
				average = (double)area[i]/count[i];
				money += average*count[i]*level[i];
			}
			cout << (unsigned long long int)money << endl;
		}
	}
	return 0;
}