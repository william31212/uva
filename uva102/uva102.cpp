#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva102.in","r",stdin);
	freopen("uva102.out","w",stdout);
	#endif
	int Arr[20];
	fill(Arr,Arr+20,0);

	while(scanf("%d",&Arr[0]) != EOF)
	{
		for (int i = 1; i < 9; ++i)
		{
			scanf("%d",&Arr[i]);
		}
		char ans[5];
		int big = INT_MAX;

		if (big > Arr[3] + Arr[6] + Arr[2] + Arr[8] + Arr[1] + Arr[4]) // BCG
		{
		 	big = Arr[3] + Arr[6] + Arr[2] + Arr[8] + Arr[1] + Arr[4];
		 	strcpy(ans,"BCG");
		}
		if (big > Arr[3] + Arr[6] + Arr[1] + Arr[7] + Arr[2] + Arr[5]) //BGC
		{
			big = Arr[3] + Arr[6] + Arr[1] + Arr[7] + Arr[2] + Arr[5];
		 	strcpy(ans,"BGC");
		}
		if (big > Arr[5] + Arr[8] + Arr[0] + Arr[6] + Arr[1] + Arr[4]) //CBG
		{
			big = Arr[5] + Arr[8] + Arr[0] + Arr[6] + Arr[1] + Arr[4];
		 	strcpy(ans,"CBG");
		}
		if (big > Arr[5] + Arr[8] + Arr[1] + Arr[7] + Arr[0] + Arr[3]) //CGB
		{
			big = Arr[5] + Arr[8] + Arr[1] + Arr[7] + Arr[0] + Arr[3];
		 	strcpy(ans,"CGB");
		}
		if (big > Arr[4] + Arr[7] + Arr[0] + Arr[6] + Arr[2] + Arr[5]) //GBC
		{
			big =  Arr[4] + Arr[7] + Arr[0] + Arr[6] + Arr[2] + Arr[5];
		 	strcpy(ans,"GBC");
		}
		if (big > Arr[4] + Arr[7] + Arr[2] + Arr[8] + Arr[0] + Arr[3]) //GCB
		{
			big =  Arr[4] + Arr[7] + Arr[2] + Arr[8] + Arr[0] + Arr[3];
		 	strcpy(ans,"GCB");
		}

		printf("%s %d\n",ans,big);

	}







	return 0;
}
	