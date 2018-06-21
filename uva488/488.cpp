#include <iostream>

using namespace std;

int main(){

	int time;
	int height,N;

	freopen("1.in","r",stdin);
	cin >> time;

	while(time--){

		cin >> height;
		cin >> N;

		while(N--){
			for(int i=1;i<=height;i++){
				for(int j=1;j<=i;j++){
				 	cout << i;
				}
				cout << endl;
			}
			for(int i=height-1;i>=1;i--){   //標號幾號
				for(int j=i-1;j>=0;j--){	//印出數量
				 	cout << i;
				}
				cout << endl;
			}
			cout << endl;
		}



	}





}