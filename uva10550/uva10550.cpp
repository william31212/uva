#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10550.in","r",stdin);
	freopen("uva10550.out","w",stdout);
	#endif
	int arr[4];
	//順時鐘前檢後，逆時鐘厚繭前
	while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]){
		int ans=0;
		if(!arr[0]&&!arr[1]&&!arr[2]&&!arr[3])
			break;
		ans += 360*3;

		if(arr[0]>arr[1])
			ans += (arr[0]-arr[1]) * 9;
		else if(arr[0]<arr[1])
			ans += (arr[0]+40 - arr[1]) * 9;
		
		if(arr[1]>arr[2])
			ans += (arr[2]+40 - arr[1]) * 9;
		else if(arr[1]<arr[2])
			ans += (arr[2]- arr[1]) * 9;
		
		if(arr[2]>arr[3])
			ans += (arr[2]-arr[3]) * 9;
		else if(arr[2]<arr[3])
			ans += (arr[2]+40 - arr[3]) * 9;
		cout << ans << endl;
	}

	return 0;
}