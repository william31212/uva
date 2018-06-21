#include <iostream>

using namespace std;

unsigned long long reverse(unsigned long long num){
	unsigned long long rev=0;
	while(num>0){
		rev = rev*10 + num%10;
		num/=10;
	}
	return rev;
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10018.in","r",stdin);
	freopen("uva10018.out","w",stdout);
	#endif
	unsigned long long times=0;
	unsigned long long num=0;
	cin >> times;
	while(times--){
		cin >> num;
		int times=0;
		if(reverse(num)==num){
			num+=reverse(num);
			times++;
		}
		while(1){
			if(reverse(num)!=num){
				num+=reverse(num);
				times++;
			}
			else{
				cout << times << " " << num << endl;
				break;
			}
		}
	}

	return 0;
}