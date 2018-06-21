#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

bool check(queue <int> &que){
    vector <int> vec(que.size());
    // cout << vec.size() << endl;

    for(unsigned int i=0;i<vec.size();i++){
        vec[i] = i+1;
    }

    stack <int> station;
    for(unsigned int i=0;i<vec.size();i++){
        station.push(vec[i]);
        while(station.size()!=0 && que.front()==station.top()){//fuck 懸
            station.pop();
            que.pop();
        }
    }

        if(station.size()==0){
            return true;
        }
        else{
            return false;
        }
}



int main(int argc, char const *argv[])
{
    int times = 0;
    int num = 0;

    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    #endif
    while(cin >> times){
        if(times==0){
            break;
        }
        while(1){
            queue <int> que;
            for(int i=0;i<times;i++){
                cin >> num;
                if(num == 0){
                    break;
                }
                que.push(num);
            }
            if(num == 0){
                break;
            }
            if(check(que)==1){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }

        }
        cout << endl;
    }


    return 0;
}
