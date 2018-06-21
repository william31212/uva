#include <iostream>
#include <string>


using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10082.in","r",stdin);
	freopen("uva10082.out","w",stdout);
	#endif
	char arr[48] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string str;

	while(getline(cin,str)){
		for(unsigned int i=0;i<str.length();i++){
			for(int j=0;j<47;j++){
				if(str[i]=='A'){
					cout << "A";
					break;
				}
				if(str[i]=='Q'){
					cout << "Q";
					break;
				}
				if(str[i]=='Z'){
					cout << "Z";
					break;
				}
				if(str[i]=='`'){
					cout << "`";
					break;
				}
				if(str[i]==' '){
					cout << " ";
					break;
				}
				if(str[i]==arr[j]){
					str[i] = arr[j-1];
					cout << str[i];
					break;
				}

			}
		}
		cout << endl;
	}



	return 0;
}