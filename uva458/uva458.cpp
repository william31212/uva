#include <iostream>

using namespace std;


int main(void){
	string str;
	while(cin >> str){

	int num = (int)'*'-'1';

	for(unsigned int i=0;i<str.length();i++){
		str[i]+=num;
	}

	cout << str << endl;

	}



}