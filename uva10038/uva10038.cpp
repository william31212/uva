#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int times = 0;
	int n =0;
	int num = 0;
	int tmp = 0;
	bool flag = 0;
    
    #ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
	#endif
	while(cin >> times){
        n = times;
		vector <int> arr;
		vector <int> check;
			while(times--)
			{
				cin >> num;
				arr.push_back(num);
			}
        vector<int>::iterator begin = arr.begin();
		vector<int>::iterator end = arr.end();
		vector<int>::iterator it;

		for(it = begin ; it != end-1 ; it++)
		{
			 tmp = abs(*it - *(it+1));
			 check.push_back(tmp);
		}



		for(int j = 1; j < n; j++){
			for(unsigned int i = 0 ; i < check.size(); i++){
				if(check[i] == j)
				{
					flag = 1;
					break;
				}
				else
				{
					flag = 0;
				}
			}
			if(flag == 0)
			{
				cout << "Not jolly" << endl;
                break;
            }
		}

		if(flag == 1 || n == 1)
		{
			cout << "Jolly" << endl;
			flag = 0;
		}
        

	}
	return 0;
}
