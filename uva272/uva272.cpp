#include <iostream>

using namespace std;

int main(){

	string str;
	string in;
	bool num=0;

	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	while(getline(cin,str)){
		for(unsigned int i=0;i<str.size();i++){
			if(str[i]=='"'&& num==0){
				in = "``";
				str.erase(i,1);
				str.insert(i,in);
				num=1;
			}
			else if(str[i]=='"'&& num==1){
				in = "''";
				str.erase(i,1);
				str.insert(i,in);
				num=0;
			}
			else if(i==str.size()-1){
				cout << str << endl;
			}
			else{
				continue;
			}
		}

	}










}