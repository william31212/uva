#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int input=0;
	int check=0;
	int arr[100]={0};
	int k=0;
	int store=0;
	int times=0;
	int time=1;
	int arrcheck[100]={0};
	int cou=0;
	int flag=0;


	cin >> times;
	while(times--){
		cin >> input;
		check = input;
		store = 0;
		cou = 0;

			while(store!=input){
				while(check>0){
					arr[k] = check%10;
					check/=10;
					k++;
				}
				for(int i=k-1;i>=0;i--){
					store = arr[i]*arr[i] + store; //算平方和
				}
				k=0; //位數清空
				arrcheck[cou] = store;//檢查位元
				cou++;//下面一位

				for(int i=0;i<cou-1;i++){
					if(arrcheck[i] == store && store != 1){//找到一樣時跳出迴圈，記得是store
						printf("Case #%d: %d is an Unhappy number.\n",time,input);
						time++;
						flag=1;
						break;
					}
				}
				if(store==1){
					printf("Case #%d: %d is a Happy number.\n",time,input);
					time++;
					break;
				}
				else if(flag==1){
                    flag=0;
                    break;
				}
				check = store;
				store = 0;
			}
	}

	return 0;
}
