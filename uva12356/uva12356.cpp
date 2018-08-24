#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva12356.in","r",stdin);
	freopen("uva12356.out","w",stdout);
	#endif

	int people,test;
	while(scanf("%d %d",&people,&test) != EOF && people && test)
	{
		//使用兩個陣列，存下每個人的左邊右邊位置分別是誰
		int left[people+1];
		int right[people+1];

		for (int i = 1; i <= people; ++i)
		{
			left[i] = i - 1;
			right[i] = i + 1;
		}

		left[1] = -1;
		right[people] = -1;
		
		while(test--)
		{
			int l,r;
			scanf("%d %d",&l,&r);

			left[right[r]] = left[l];

			if (left[l] != -1)
			{
				printf("%d ", left[l]);
			}
			else
			{
				printf("* ");
			}

			right[left[l]] = right[r];


			if (right[r] != -1)
			{
				printf("%d\n", right[r]);
			}
			else
			{
				printf("*\n");
			}


		}

		printf("-\n");
			
	}

	return 0;
}
	
