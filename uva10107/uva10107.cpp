#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10107.in","r",stdin);
	freopen("uva10107.out","w",stdout);
	#endif

	int i=0,tmp=0;
	int arr[10000];
	while(cin >> arr[i]){
		i++;
		if(i!=0){
			sort(arr,arr+i);
		}
		if(i%2==0){
			tmp = i/2;
			cout <<(arr[tmp-1]+arr[tmp])/2 << endl;
		}
		else{
			tmp = i/2;
			cout << arr[tmp] << endl;
		}
	}
	return 0;
}