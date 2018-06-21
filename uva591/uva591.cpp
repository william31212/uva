#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva591.in","r",stdin);
	freopen("uva591.out","w",stdout);
	#endif

	int times=0;
	int fuck=0;

	while(cin >> times){
		if(times==0){
			break;
		}
		int arr[times]={0};
		int sum = 0;
		int ans = 0;
		for(int i=0;i<times;i++){
			cin >> arr[i];
			sum += arr[i];
		}
		sum/=times;
		for(int i=0;i<times;i++){
			if(sum<arr[i]){
				ans += arr[i]-sum;
			}
		}
		fuck++;
		printf("Set #%d\n",fuck);
		printf("The minimum number of moves is %d.\n",ans);
		printf("\n");
	}

	return 0;
}