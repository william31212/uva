#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10340.in","r",stdin);
	freopen("uva10340.out","w",stdout);
	#endif
	string s;
	string t;
	while(cin >> s >> t){
		bool flag=0;
		unsigned int i=0;
		for(unsigned int j=0;j<t.length();j++){
			if(s[i]==t[j]){
				i++;
			}
			if(i==s.length()){
				flag = 1;
				break;
			}
		}
		if(flag){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}