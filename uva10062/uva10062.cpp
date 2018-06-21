#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10062.in","r",stdin);
	freopen("uva10062.out","w",stdout);
	#endif

	string str;
	int cal[128]={0};
	bool check=0;
	while(getline(cin,str)){
		if(check==1){
			cout << endl;
		}
		for(unsigned int i=0;i<str.length();i++){
			cal[(int)str[i]]+=1;
		}
		while(1){
			int small=100000;
			int small_i=0;
			bool flag = 0;
			for(int i=127;i>=0;i--){
				if(small>cal[i] && cal[i]!=0){
					small = cal[i];
					small_i = i;
					flag = 1;
				}
			}
			if(flag==0){
				break;
			}
			else{
				cout << small_i << " " << small << endl;
				cal[small_i]=0;
			}
		}
		check = 1; //排版問題
	}

	return 0;
}