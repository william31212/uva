#include <iostream>

using namespace std;

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11219.in","r",stdin);
	freopen("uva11219.out","w",stdout);
	#endif

	int times;
	while( scanf("%d",&times) != EOF)
	{
		int t_day , t_month , t_year;
		int birth_day , birth_month , birth_year;
		int count = 1;
		while(times--)
		{
			scanf("%d/%d/%d",&t_day,&t_month,&t_year);
			scanf("%d/%d/%d",&birth_day,&birth_month,&birth_year);

			printf("Case #%d: ", count++);
			if (birth_year > t_year)
			{
				printf("Invalid birth date\n");
			}

			else if (birth_year == t_year)
			{
				if (birth_month > t_month) 
				{
					printf("Invalid birth date\n");
				}

				else if (birth_month == t_month)
				{
					if (birth_day > t_day)
					{
						printf("Invalid birth date\n");
					}
					else
					{
						printf("0\n");
					}
				}

				else
				{
					printf("0\n");
				}
			}

			else
			{
				if (birth_month > t_month)
				{
					if (t_year - birth_year - 1> 130)
					{
						printf("Check birth date\n");
					}
					else
					{
						printf("%d\n", t_year - birth_year - 1);
					}
				}

				else if (birth_month == t_month)
				{
					if (birth_day > t_day)
					{
						if (t_year - birth_year - 1> 130)
						{
							printf("Check birth date\n");
						}
						else
						{
							printf("%d\n", t_year - birth_year - 1);
						}
					}
					else 
					{
						if (t_year - birth_year > 130)
						{
							printf("Check birth date\n");
						}
						else
						{
							printf("%d\n", t_year - birth_year);
						}
					}
				}

				else
				{
					if (t_year - birth_year > 130)
					{
						printf("Check birth date\n");
					}
					else
					{
						printf("%d\n", t_year - birth_year);
					}
				}

			}
		}
		
	}
	return 0;
}
	