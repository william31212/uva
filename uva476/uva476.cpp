#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	char r;
	int times=0;
	float x_left=0,x_right=0,y_up=0,y_down=0;
	float array[4][10];
	float x=0,y=0;
	int k=1;
	bool flag = 0;
	while(cin >> r){
		if(r=='*'){
			break;
		}
		cin >> x_left >> y_up >> x_right >> y_down;
		array[0][times] = x_left;
		array[1][times] = x_right;
		array[2][times] = y_down;
		array[3][times] = y_up;
		times++;
	}

	while(cin >> x >> y){
		flag = 0;
		if((int)x==9999 && (int)y==9999){
			break;
		}
		for(int i=0;i<times;i++){
            if((x > array[0][i] && x < array[1][i]) && (y > array[2][i] && y < array[3][i])){
				printf("Point %d is contained in figure %d\n",k,i+1);
				flag = 1;
				if(i==times-1){
					k++;
				}
			}
			else if(i==times-1 && flag==0){
				printf("Point %d is not contained in any figure\n",k);
				k++;
			}
			else{
				if(i==times-1){
					k++;
				}
			}


		}

	}
	return 0;
}
