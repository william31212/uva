#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


void construct_tree(int input[],int segement[], int left ,int right , int pos)
{
	if (left == right)
	{
		segement[pos] = input[left];
		return;
	}
	else
	{
		int mid = (left + right) / 2;
		construct_tree(input,segement,left,mid,2*pos+1);// (left + mid / 2)
		construct_tree(input,segement,mid+1,right,2*pos+2);// (mid+1 + right / 2)
		segement[pos] = max(segement[2*pos+1],segement[2*pos+2]);
	}
}

int range_max(int segement[],int range_left,int range_right,int left,int right,int pos)
{
	if (range_left <= left && range_right >= right)
	{
		return segement[pos];
	}
	if (range_left > right || range_right < left)
	{
		return -1000000;
	}
	else
	{
		int mid = (left + right) / 2;
		return max(range_max(segement , range_left , range_right , left , mid , 2*pos+1), range_max(segement , range_left , range_right ,mid+1 ,right ,2*pos+2));
	}


}




int main()
{
	#ifdef DBG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int input[4]={-1,2,4,0};
	int segement[7];
	fill(segement,segement+7,0);

	construct_tree(input,segement,0,3,0);

	for (int i = 0; i < 7; ++i)
	{
		printf("%d ", segement[i]);
	}
	printf("\n");

	int left,right;

	while(scanf("%d %d",&left,&right) != EOF)
		printf("max:%d\n",range_max(segement,left,right,0,3,0));
	
	return 0;

}