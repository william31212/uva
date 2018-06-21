#include <iostream>  
#include <map>  
#include <vector>

using namespace std;

map <int, vector<int> > Map;

int main(void){

	#ifndef ONLINE_JUDGE
	freopen("online.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif


	int length=0;
	int times=0;
	int num=0;
	unsigned int Ordinal=0;

	while(cin >> length >> times){
		Map.clear();
		for(int i=0;i<length;i++){
			cin >> num;
			Map[num].push_back(i+1);
		}
		for(int i=0;i<times;i++){
			cin >> Ordinal >> num; 
			if(Map[num].size()<Ordinal){
				cout << "0\n";
			}
			else{
				cout << Map[num][Ordinal-1] << "\n";
			}
		}		
	}
	return 0;
}