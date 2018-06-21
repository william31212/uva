#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva579.in","r",stdin);
	freopen("uva579.out","w",stdout);
	#endif

	float hour=0;
	float min=0;
	char garbage;
	float tmp=0;
	float ans=0;

	while(cin >> hour >> garbage >> min){
		if(hour==0 && min==0){
			break;
		}
		hour = hour * 30;
		tmp = min * 0.5;
		hour+=tmp;
		if(min==0){
			min = 60;
		}
		min = min * 6;
		ans = abs(hour-min);
		if(ans==360){
			ans = 0;
		}
		else if(ans >= 180){
			ans = 360 - ans;
		}
		printf("%.3f\n",ans);
	}
	

	return 0;
}