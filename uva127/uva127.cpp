#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct Card
{
	char value;
	char suit;
};


int main(void){
	#ifndef ONLINE_JUDGE
	freopen("uva127.in","r",stdin);
	freopen("uva127.out","w",stdout);
	#endif

	stack <Card> pile[60]; 
	Card input;


	while(scanf("%c",&input.value) != EOF)
	{	
		if (input.value == '#')
			break;

		for (int i = 0; i < 56; ++i)//初始化
		{
			while(!pile[i].empty()) //pile的其中一個如果不是空的，清到變成空就跳出
			{
				pile[i].pop();//就清掉
			}
		}
		char garbage;
		//因為要檢查前面三格跟一格，所以從第四格開始存

		//因為前面input有一個%c判斷end，因此要做例外處理
		scanf("%c%c",&input.suit,&garbage);
		pile[3].push(input);

		
		//還有51章牌要input進來
		 for (int i = 1; i <= 51; i++)
		 {
		 	scanf("%c%c%c",&input.value,&input.suit,&garbage);
		 	pile[i+3].push(input);
		 }


		 int previous_1 , previous_3;
		 int count1 , count3;
		 for (int i = 3; i < 55; ++i)
		 {
		 	if (pile[i].empty())
		 		continue;

		 	previous_1 = i;//找出正確往前一格的位置
		 	previous_3 = i;//找出正確往前三格位置
		 	count1 = 1;
		 	count3 = 3;
		 
		 	while( count3 ) //扣到零就知道往前推多少格
		 	{
		 		if ( count1 )
		 			previous_1--;

		 		previous_3--;

		 		if (previous_3 < 3)
		 			break;


		 		if (!pile[previous_3].empty())//前面有郎，才會將計數器往下扣
		 		{
		 			if ( count1 )
		 			{
		 				count1--;
		 			}

		 			count3--;
		 		}

		 	} 

		 	if ( !pile[previous_3].empty() &&
		 		  ( pile[previous_3].top().value == pile[i].top().value ||
		 		  pile[previous_3].top().suit == pile[i].top().suit )
		 		)
		 	{
		 		pile[previous_3].push(pile[i].top());
		 		pile[i].pop();
		 		i = previous_3 - 1; //必須要從前一個開始檢查，不然會漏掉
		 	}

		 	else if ( !pile[previous_1].empty() &&
		 		  ( pile[previous_1].top().value == pile[i].top().value ||
		 		  pile[previous_1].top().suit == pile[i].top().suit )
		 		)
		 	{
		 		pile[previous_1].push(pile[i].top());
		 		pile[i].pop();
		 		i = previous_1 - 1; //必須要從前一個開始檢查，不然會漏掉
		 	}
		 	
		 }


		// output 
		int pilenum = 0;

		for (int i = 3; i < 55; ++i)
		{
			if ( !pile[i].empty() )
			{
				pilenum++;
			}
		}

		if (pilenum == 1)
		{
			printf("%d pile ", pilenum);
		}

		else if (pilenum > 1)
		{
			printf("%d piles ", pilenum);
		}

		printf("remaining:");

		for (int i = 3; i < 55; ++i)
		{
			if (!pile[i].empty())
			{
				printf(" %llu", pile[i].size());
			}
		}

		putchar('\n');

	} 
	
	return 0;
}
	