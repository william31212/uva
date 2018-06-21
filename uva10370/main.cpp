#include <iostream>
#include <cstdio>

using namespace std;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	#endif
	int times = 0;
	int num = 0;
	int average = 0;
	int people = 0;
	float ans = 0;

	cin >> times;

	while(times--){
		cin >> num;
		int arr[num]={0};
		for(int i=0;i<num;i++){
			 cin >> arr[i];
			 average+=arr[i];
		}
		average/=num;
		for(int i=0;i<num;i++){
			if(arr[i]>average){
				people++;
			}
			 
		}
		ans = (float)people/(float)num;
		printf("%.3f%%\n",ans*100);
		ans = 0;
		average = 0;
		people = 0;
	}
}