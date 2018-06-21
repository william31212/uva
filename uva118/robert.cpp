#include <iostream>

using namespace std;

void direction(char dir){
	if(dir == 'N'){
		return 0;
	}
	else if(dir == 'E'){
		return 1;
	}
	else if (dir == 'S'){
		return 2;
	}
	else if (dir == 'W'){
		return 3;
	}

}





int main(void){
	freopen("1.in","r",stdin);
	int x,y;
	int R=0,L=0;
	char dir;
	string route;
	cin >> x >> y;
	int arr[x][y];

	for(int i=0;i<y+1;i++){
		for(int j=0;j<x+1;j++){ 
			arr[j][i] = 0;			//初始化
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}


	while(scanf("%d %d %c",&x,&y,&dir)!= EOF){
			cin >> route;
			arr[x][y] = 1;
			int d = direction(dir);
			for(unsigned int i=0;i<route.length();i++){
				if(route[i]=='R'){
					d = (d+1) % 4;
				}
				else if(route[i]=='L'){
					d = (d+3) % 4;
				}
				else{
					if(d==0){
						arr[x][y]
					}
					else if(d==1){

					}
					else if(d==2){

					}
					else{

					}
				}
			}



	}



}