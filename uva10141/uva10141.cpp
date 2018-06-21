#include <iostream>
#include <cstdio>

using namespace std;

struct company{
	string name;
	double d;
	int r;
};


int main(void){
	// #ifndef ONLINE_JUDGE
	// freopen("uva10141.in","r",stdin);
	// freopen("uva10141.out","w",stdout);
	// #endif
	int n=0,p=0;
	char service[1000][80];
	while(cin >> n >> p){
		if(!n && !p){
			break;
		}
		for(int i=0;i<n;i++){
			scanf("\n"); //先吃一個換行，因為getline會偷吃一個換行
			cin.getline(service[i],80);
		}
		// for(int i=0;i<n;i++){
		// 	cout << service[i] << endl;
		// }
		float big_money=0;
		int big_check=0;
		string garbage;
		string big_name;
		while(p--){
			company A;
			getline(cin,A.name);
			cin >> A.d >> A.r;
			for(int i=0;i<A.r;i++){
				scanf('\n');
				getline(cin,garbage);
			}
			if(A.r > big_check){
				big_check = A.r;
				big_name = A.name;
			}
			else if(A.r == big_check){
				continue;
			}
			else if
			if(A.d < big_money){
				big_money = A.d;
			}


		}
		
	}


	return 0;
}
