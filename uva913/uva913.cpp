#include <iostream>

using namespace std;



int main(int argc, char const *argv[])
{
	long long int num =0;
	while(cin >> num){
		int plus = 0;
		// int odd = 1;
		// for(int i=0;i<(num+3)/2;i++){ // 幾行
		// 	for(int j=1;j<2*i;j++){ //奇數
		// 		 cout << odd << " ";
		// 		 odd+=2;
		// 	}
		// 	 cout << endl;
		// }
		// odd = (odd-4)*3;
		// cout << odd << endl;
		plus = (num - 3) / 2;
		if(num==3){
			num = (1+num)*2 - 1;
		}
		else if(num>3){
			num = (1+num) * (2 + plus) - 1;
		}
		num = (num-2) * 3;
		cout << num << endl;
	}
	return 0;
}