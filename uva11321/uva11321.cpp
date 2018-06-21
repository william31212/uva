#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
int M = 0;

int compare(const void *a, const void *b){
	int x = *(int*)a;
	int y = *(int*)b;
	
	if(x%M > y%M){
		return 1;
	}
	if(x%M < y%M){
		return -1;
	} 
	if(x%M == y%M){
		if(x%2!=0 && y%2==0){
			return -1;
		}
		if(x%2==0 && y%2!=0){
			return 1;
		}
		if(x%2==0 && y%2==0){
			return x>y? 1:-1;
		}
		if(x%2!=0 && y%2!=0){
			return x>y? -1:1;
		}
	}
	
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	#endif
	int num = 0;
	int length = 0,mo = 0;
	while(cin >> length >> mo){
		if(length==0 && mo==0){
			cout << "0 0" << endl;
			break;
		}
		int arr[length] = {0};
		M = mo;
		for(int i=0;i<length;i++){
			cin >> num;
			arr[i] = num;
		}

		qsort(arr,length,sizeof(int),compare);
		cout << length << " " << mo << endl;
		for(int i=0;i<length;i++){
			cout << arr[i] << endl;
		}
	}
	
	return 0;
}