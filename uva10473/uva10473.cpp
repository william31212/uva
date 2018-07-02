#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

int main(void){
	// #ifndef ONLINE_JUDGE
	// freopen("uva10473.in","r",stdin);
	// freopen("uva10473.out","w",stdout);
	// #endif

	stringstream ss;   
	string str_num;
	
	while(cin >> str_num){
		bool flag = 0;
		int num=0;
		ss.str("");
		ss.clear();
		if(str_num[0]=='-'){
			break;
		}

		if(str_num[0]=='0' && str_num[1]=='x'){
			str_num[1]='0';
			flag = 1;
		}
		ss << str_num;
		
		if(flag==1){
			ss >> setbase(16) >> num;
			cout << setbase(10) << num << endl;
		}
		else{
			ss >> setbase(10) >>num;
			cout << "0x" << uppercase << setbase(16) << num << endl;
		}
	}
	

	return 0;
}