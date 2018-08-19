#include <iostream>
#include <cstdio>

//linklist實作這題，切記用double
using namespace std;

bool flag = 0;

struct node
{
	unsigned char name;
	double price;
	node *next;
	node()
	{
		next = NULL;
	}
};


node *head , *current;

void add(unsigned char tmp_name	, double tmp_price)
{
	tmp_price/=	(double)100;

	if (!flag)
	{
		current = new node;
		current->name = tmp_name;
		current->price = tmp_price;
		current->next = new node;
		head = current;
		// printf("%x\n", current->next);
		
		flag = 1;
	}


	else
	{
		current = current->next;
		current->name = tmp_name;
		current->price = tmp_price;
		current->next = new node;
	}
	
}


int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva11340.in","r",stdin);
	freopen("uva11340.out","w",stdout);
	#endif


	int times = 0;
	scanf("%d", &times);

	while(times--)
	{
		int word;
		flag = 0;
		
		scanf("%d", &word);
		getchar();

		for (int i = 0; i < word; ++i)
		{
			unsigned char name_tmp;
			double price_tmp;
			cin >> name_tmp >> price_tmp;
			getchar();
			
			add(name_tmp,price_tmp);
		}

		unsigned char article;
		double sum = 0;
		int line;

		
		cin >> line;
		line += 1;
		while(line)
		{
			scanf("%c",&article);

			if (article == '\n')
			{
				line--;
				continue;
			}

			node *it = head;
			while(it->next != NULL)
			{
				// printf("%c %f\n", it->name, it->price);
				if (article == it->name)
				{
					// printf("%c\n", it->name);
					sum += it->price;
				}

				it = it->next;
			}
		}
		printf("%.2f$\n", sum);

	}

	return 0;
}
	