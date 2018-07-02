#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10499.in","r",stdin);
	freopen("uva10499.out","w",stdout);
	#endif
	long long num=0;
	while(cin >> num){
		if(num<0){
			break;
		}
		else if(num==1)
			cout << "0%" << endl;
		else if(num==2){
			cout << "50%" << endl;
		}
		else{
			num-=2;
			cout << 50+(num*25) << "%" << endl;
		}
	}

	return 0;
}