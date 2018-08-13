#include <iostream>
#include <cstring>

using namespace std;



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva145.in","r",stdin);
	freopen("uva145.out","w",stdout);
	#endif


	float a[3],b[3],c[3],d[3],e[3];

	a[0] = 0.10;
	a[1] = 0.06;
	a[2] = 0.02;

	b[0] = 0.25;
	b[1] = 0.15;
	b[2] = 0.05;

	c[0] = 0.53;
	c[1] = 0.33;
	c[2] = 0.13;

	d[0] = 0.87;
	d[1] = 0.47;
	d[2] = 0.17;

	e[0] = 1.44;
	e[1] = 0.80;
	e[2] = 0.30;


	char num[10];
	char step;
	int begin_hour,begin_min,end_hour,end_min;
	while(scanf("%c",&step) != EOF && (step != '#') )
	{
		scanf("%s",num);
		scanf("%d %d %d %d", &begin_hour , &begin_min, &end_hour ,& end_min);
		// printf("%c %s %d %d %d %d\n", step , num , begin_hour , begin_min , end_hour , end_min);

		
		getchar();


		int start;
		int finish;

		int time_1 = 0;
		int time_2 = 0;
		int time_3 = 0;
		float ans = 0;

		start = begin_hour * 60 + begin_min;
		finish = end_hour * 60 + end_min;
		bool phone[1440];
		fill(phone,phone+1440,0);

		// printf("%d %d\n", start, finish);

		if (start > finish)
		{
			for (int i = start; i < 1440; ++i)
			{
				phone[i] = 1;
			}

			for (int i = 0; i < finish; ++i)
			{
				phone[i] = 1;
			}
	 
		}
		
		else if (start < finish)
		{
			for (int i = start; i < finish; ++i)
			{	
		 		phone[i] = 1;
			}
		}

		else 
		{
			fill(phone,phone+1440,1);
		}

		// for (int i = 0; i < 1440; ++i)
		// {
		// 	printf("%d %d\n",i,phone[i]);
		// }

		for (int i = 0; i < 1440; ++i)
		{
			if ( ( (i >= 1320 && i < 1440) || (i >= 0 && i < 480) ) && phone[i])
			{
				time_3++;
			}

			if (i >= 480 && i < 1080 && phone[i])
			{
				time_1++;
			}

			if (i >= 1080 && i < 1320 && phone[i])
			{
				time_2++;
			}
		}
		

		if (step == 'A')
		{
			ans += a[0] * (float)time_1;
			ans += a[1] * (float)time_2;
			ans += a[2] * (float)time_3;
		}

		if (step == 'B')
		{
			ans += b[0] * (float)time_1;
			ans += b[1] * (float)time_2;
			ans += b[2] * (float)time_3;
		}

		if (step == 'C')
		{
			ans += c[0] * (float)time_1;
			ans += c[1] * (float)time_2;
			ans += c[2] * (float)time_3;
		}

		if (step == 'D')
		{
			ans += d[0] * (float)time_1;
			ans += d[1] * (float)time_2;
			ans += d[2] * (float)time_3;
		}

		if (step == 'E')
		{
			ans += e[0] * (float)time_1;
			ans += e[1] * (float)time_2;
			ans += e[2] * (float)time_3;
		}

		printf("  %8s %5d %5d %5d  %c %7.2f\n", num, time_1, time_2, time_3, step, ans);
	}

	return 0;
}
	
