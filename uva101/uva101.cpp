#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

int now[25];//表示現在位置
vector<int>::iterator it;


int main(void){
	 
	#ifndef ONLINE_JUDGE
	freopen("uva101.in","r",stdin);
	freopen("uva101.out","w",stdout);
	#endif

	int N;
	while( scanf("%d",&N) != EOF )
	{
		char word1[5];
		char word2[5];
		int a;
		int b;	
		vector <int> v[25];//每列的stack
		stack <int> tmp;

		for (int i = 0; i < N; ++i)
		{
			now[i] = i;
			v[i].push_back(i);
		}


		
		while( scanf("%s",word1) && strcmp(word1 , "quit") != 0)
		{
			scanf("%d %s %d",&a,word2,&b);

			if (now[a] == now[b])
			{
				continue;
			}

			if ( !strcmp( word1 , "move") && !strcmp( word2 , "onto") )
			{

				while(v[now[a]].back() != a) //最尾端非a，代表a上方要回家
				{
					v[v[now[a]].back()].push_back(v[now[a]].back());//放回最開始的地方
					now[v[now[a]].back()] = v[now[a]].back(); //now做更新
					v[now[a]].pop_back();
				}
				

				while(v[now[b]].back() != b) //最尾端非b，代表b上方要回家
				{
					v[v[now[b]].back()].push_back(v[now[b]].back());//放回最開始的地方
					now[v[now[b]].back()] = v[now[b]].back(); //now做更新
					v[now[b]].pop_back();
					

				}

				v[now[b]].push_back(v[now[a]].back());
				v[now[a]].pop_back();
				now[a] = now[b];

			}

			else if ( !strcmp( word1 , "move") && !strcmp( word2 , "over") )
			{
				while(v[now[a]].back() != a) //最尾端非a，代表a上方要回家
				{
					v[v[now[a]].back()].push_back(v[now[a]].back());//放回最開始的地方
					now[v[now[a]].back()] = v[now[a]].back(); //now做更新
					v[now[a]].pop_back();
					
				}

				v[now[b]].push_back(v[now[a]].back());				
				v[now[a]].pop_back();
				now[a] = now[b];

			}

			else if ( !strcmp( word1 , "pile") && !strcmp( word2 , "onto") )
			{
				while(v[now[b]].back() != b) //最尾端非b，代表b上方要回家
				{
					v[v[now[b]].back()].push_back(v[now[b]].back());//放回最開始的地方
					now[v[now[b]].back()] = v[now[b]].back(); //now做更新
					v[now[b]].pop_back();
					
				}

				bool flag = 0;

				while(v[now[a]].back() != a) //a上方全部送到b身上，用stack暫時存
				{
					tmp.push(v[now[a]].back());
					now[v[now[a]].back()] = now[b];
					v[now[a]].pop_back();
					flag = 1;
					
				}

				
				if (flag)
				{
					tmp.push(v[now[a]].back());
			
					int proplem = now[a];
					now[v[now[a]].back()] = now[b];
					v[proplem].pop_back();
			
					while(!tmp.empty())
					{
						v[now[b]].push_back(tmp.top());
						tmp.pop();
					}
				}

				else
				{
					v[now[b]].push_back(v[now[a]].back());
					v[now[a]].pop_back();
					now[a] = now[b];
				}
				
			
			}

			else if ( !strcmp( word1 , "pile") && !strcmp( word2 , "over") )
			{
				bool flag = 0;

				
				while(v[now[a]].back() != a) //a上方全部送到b身上，用stack暫時存
				{
					tmp.push(v[now[a]].back());
					now[v[now[a]].back()] = now[b];
					v[now[a]].pop_back();
					flag = 1;
					
				}

				
				if (flag)
				{
					tmp.push(v[now[a]].back());
	
					int proplem = now[a];
					now[v[now[a]].back()] = now[b];
					
					v[proplem].pop_back();
			
					while(!tmp.empty())
					{
						v[now[b]].push_back(tmp.top());
						tmp.pop();
					}
				}

				else
				{
					v[now[b]].push_back(v[now[a]].back());
					v[now[a]].pop_back();
					now[a] = now[b];
				}
				
			}

		}
		

		//output
		for (int i = 0; i < N; ++i)
		{
			printf("%d:", i);
			for (it = v[i].begin() ; it != v[i].end() ; ++it)
			{
				printf(" %d", *it);
			}
			printf("\n");
		}

	} 

	
	return 0;
}
	