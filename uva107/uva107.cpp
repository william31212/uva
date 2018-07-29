#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva107.in","r",stdin);
	freopen("uva107.out","w",stdout);
	#endif

	int H,W;

	while(scanf("%d %d",&H,&W) && H && W)
	{
		double tmp = log(H) / log(W);

		int i = 1;
		int i_max = 2147483645;
		int mid = (i + i_max) / 2;

		while(i != i_max)
		{
			if (log(mid+1) / log(mid) - tmp > 0.000000000001) //比原答案還大
			{
				i = mid + 1;	

			}
			else if (log(mid+1) / log(mid) - tmp < -0.000000000001) //比原答案還小
			{
				i_max = mid;
			}
			else //誤差小於0.000000000001則跳出
				break;
			mid = (i + i_max) / 2;
			printf("%d\n",mid);
		}

		int N = mid;
		int k;

		if (N == 1)
		{
			k = round(log(H) / log(2));
		}
		else{
			k = round(log(W) / log(N));
		}
		
		
		

		int total_height = H;
		int H_tmp;
		int no = 0;

		H_tmp = H;



		for (int i = 0; i < k; ++i)
		{	
			total_height += H_tmp *((double)1 / (double)(N+1)) * pow(N,i+1);
			// printf("Hei%d\n",total_height);
			H_tmp = H_tmp * ((double)1/(double)(N+1));
			// printf("tmp%d\n",H_tmp);
			no += pow(N,i);
		}

		printf("%d %d\n", no ,total_height);
 		
    }
	
	return 0;
}
	