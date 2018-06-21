#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10222.in","r",stdin);
	freopen("uva10222.out","w",stdout);
	#endif
	
	char key[48]="1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	string fuck;
	while(getline(cin,fuck)){
		for(unsigned int i=0;i<fuck.length();i++){
			for(int j=0;j<48;j++){
				if(fuck[i]==key[j]){
					fuck[i] = key[j-2];
				}
			}
		}
		cout << fuck << endl;
	}

	return 0;
}