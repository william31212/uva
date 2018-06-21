#include <iostream>
#include <queue>
#include <stack>	

using namespace std;

bool check(queue <int> &que){
	vector <int> vec(que.size());
	stack <int> station;
	for(unsigned int i=0;i<que.size();i++){
		vec[i] = i+1;
	}

	for(unsigned int i=0;i<vec.size();i++){
		station.push(vec[i]);
		while(que.front()==station.top() && station.size()!=0){ //queue的第一個與stack的頂端一模一樣就先pop
			//再用size做迴圈
			station.pop();
			que.pop();
		}
	}
		if(station.size()==0){
			return true;
		}
		else{
			return false;
		}

}






int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	#endif
	int times = 0;
	int num = 0;
	queue <int> que;


	while(cin >> times){
		while(1){
			for(int i=0;i<times;i++){
				cin >> num;
				if(num == 0){
					break;
				}
				que.push(num);
			}
			if(check(que)==1){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}
	}
	
	
	return 0;
}