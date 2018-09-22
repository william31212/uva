#include <bits/stdc++.h>

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
	if (qleft > right || qright < left)
	{
		return -100000;
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
	
	return 0;

}