#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva10035.in","r",stdin);
	freopen("uva10035.out","w",stdout);
	#endif
	int num1=0,num2=0;



	while(cin >> num1 >> num2){
		int tmp1=0,tmp2=0,carry=0;
		int tmp=0;
		int ans=0;
		if(num1==0 && num2==0){
			break;
		}

		while(1){
			if(num1>0 && num2>0){
				tmp1 = num1%10;
				num1/=10;
				tmp2 = num2%10;
				num2/=10;
				tmp += tmp1 + tmp2 + carry;
				carry = 0;
				if(tmp>=10){
					carry+=1;
					ans++;
				}
				tmp = 0;
			}
			else{
				break;
			}
		}

            while(num1==0 && num2>0){
				tmp2 = num2%10;
				tmp += carry + tmp2;
				carry = 0;
				if(tmp>=10){
					ans++;
					carry=1;
				}
				else if(tmp<10){
					break;
				}
				tmp = 0;
				num2/=10;
            }
			while(num1>0 && num2==0){
				tmp1 = num1%10;
				tmp += carry + tmp1;
				carry = 0;
				if(tmp>=10){
					ans++;
					carry=1;
				}
				else if(tmp<10){
					break;
				}
				tmp = 0;
				num1/=10;
			}
		if(ans==0){
			printf("No carry operation.\n");
		}
		else if(ans==1){
			printf("%d carry operation.\n",ans);
		}
		else if(ans>1){
			printf("%d carry operations.\n",ans);
		}
	}

	return 0;
}
