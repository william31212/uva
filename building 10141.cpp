#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct company
{
	float d;
	int r;
	char name[1000];

	company(){
		d =0.f;
		r =0;
	}
};




int main(void){
	int n=0,p=0;
	int plus=1;
	#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	#endif
	while(cin >> n >> p ){	
		char fuck;
		company a;
		company best;	
		if(!n && !p){
			break;
		}
		for(int i=0;i<n+1;i++){
			while(1){
				fuck = getchar();
				if(fuck=='\n'){
					break;
				}
			}
		}
		for(int i=0;i<p;i++){
			cin.getline(a.name,1000);
			cin >> a.d >> a.r;
			for(int i=0;i<a.r+1;i++){
				while(1){
					fuck = getchar();
					if(fuck=='\n'){
						break;
					}
				}
			}
			if(best.r < a.r){
				best.r = a.r;
				strcpy(best.name,a.name);
			}
			else if(best.r==a.r && best.d > a.d){
				strcpy(best.name,a.name);
			}
		}
		printf("RFP #%d\n",plus);
		printf("%s\n",best.name);
		plus++;
	}
}