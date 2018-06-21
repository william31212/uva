#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

int main(){
	string input;
	while(getline(cin,input)){
		list<char> data;
		list<char>::iterator data_iterator; 
		data_iterator = data.begin();

		for(unsigned int i=0;i<input.length();i++){
			if(input[i]=='['){
				data_iterator = data.begin();
			}
			else if(input[i]==']'){
				data_iterator = data.end();
			}
			else{
				data.insert(data_iterator,input[i]);
			}
		}

		for(data_iterator = data.begin();
			data_iterator != data.end();
			data_iterator++){
			printf("%c",*data_iterator);
		}
		printf("\n");
	}
}
