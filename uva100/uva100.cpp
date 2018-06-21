#include <iostream>

using namespace std;

int odd(int *a){
	*a = 3 * (*a) + 1;
	return *a;
}

int even(int *a){
	*a/=2;
	return *a;
}

int main(void){

	#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	#endif
	int start=0;
	int endnum=0;
	int times=0;
	int big=0;
	int input=0;
	bool flag = 0;

	while(cin >> start >> endnum){
		if(start > endnum){
			int tmp;
			tmp = start;
			start = endnum;
			endnum = tmp;
			flag = 1;
		}
		else{
			flag = 0;
		}

		for(int i=start;i<=endnum;i++){
			input = i;
			times++;
			while(input!=1){
				if(input%2==0){
					even(&input);
					times++;
				}
				else{
					odd(&input);
					times++;
				}
			}
			if(times > big){
				big = times;
			}
			times = 0;
		}
		if(flag == 0){
			cout << start << " " << endnum << " " << big << endl;
		}
		else{
			cout << endnum << " " << start << " " << big << endl;
		}
			big = 0;
	
	}

}