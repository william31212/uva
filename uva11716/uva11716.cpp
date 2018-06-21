#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;


int main(){
	#ifndef ONLINE_JUDFE
	freopen("1.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int input;
	double fuck;
	char str[10001];
	while(scanf("%d\n",&input)!=EOF){
		while(input--){
			gets(str);
			fuck = sqrt(strlen(str));
			if(fuck-(int)fuck != 0){
				cout << "INVALID\n";
			}
			else{
				int k=0;
				char arr[(int)fuck][(int)fuck];
				for(int i=0;i<fuck;i++){
					for(int j=0;j<fuck;j++){
						arr[i][j] = str[k];
						k++;
 					}
				}
				for(int i=0;i<fuck;i++){
					for(int j=0;j<fuck;j++){
						cout << arr[j][i];
					}
				}
				cout << "\n";
			}
		}
	}
}