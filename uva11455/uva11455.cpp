#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int a[4];
	int times= 0;
	cin >> times;

	while(times--){
		for(int i=0;i<4;i++){
			cin >> a[i];
		}
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				int tmp=0;
				if(a[i] > a[j]){
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3]){
			cout << "square" << endl;
		}
		else if(a[0]==a[1] && a[2]==a[3]){

			cout << "rectangle" << endl;
		}
		else if((a[0]+a[1]+a[2])>a[3]){
			cout << "quadrangle" << endl;
		}
		else{
			cout << "banana" << endl;
		}

	}
	return 0;
}