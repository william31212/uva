#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct company{
	string name;
	double d;
	int r;
};


int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10141.in","r",stdin);
	freopen("uva10141.out","w",stdout);
	#endif
	int n=0,p=0;
	int counter=1;
	bool flag=0;
	string service;
	while(cin >> n >> p){	
		if(!n && !p){
			break;
		}
		if(flag)
			cout << endl;
		flag = 1;
		for(int i=0;i<n;i++){
			scanf("\n"); //先吃一個換行，因為getline會偷吃一個換行
			getline(cin,service);
		}
		// for(int i=0;i<n;i++){
		// 	cout << service[i] << endl;
		// }
		string garbage;
		company A;
		company Best;
		Best.r=0;
		Best.d=100000;
		while(p--){
			getline(cin , A.name);
			cin >> A.d >> A.r;
			getchar();
			for(int i=0;i<A.r;i++){
				getline(cin,garbage);
			}
			if(A.r!=0){
				if(A.r > Best.r){
					Best = A; 
				}
				else if(A.r == Best.r && A.d < Best.d){
					Best = A;
				}
			}
		}
		cout << "RFP #" << counter << "\n" << Best.name.c_str() << "\n";
		counter++;	
	}
	return 0;
}