#include <bits/stdc++.h>

using namespace std;

struct fuck
{

}

int main()
{
    fstream fs;
    fs.open("README.md",ios::in | ios::out);

    int num;
    string str;
    printf("enter the question number:\n");
    cin >> num;
    printf("enter the question name:\n");
    cin >> str;

    string tmp;
    bool flag = 0;
    vector <string> vec;
    long len = 0;
    while(getline(fs,tmp))
    {
        char is_num[] = "0";
        memset(is_num,'0',sizeof(is_num));
        int k = 0;
        int problem = 0;
        if (tmp[6] == 'u' && tmp[7] == 'v' && tmp[8] == 'a')
        {
            for (int i = 9; tmp[i] != ' ' ; ++i)
            {
                is_num[k++] = tmp[i];
            }

            problem = atoi(is_num);

            if (num < problem)
            {
                cout << len << '\n';
                while(getline(fs,tmp))
                {
                    vec.push_back(tmp);
                }
                break;
            }

            len += tmp.size();
        }
        else
        {
            cout << len << '\n';
            len += tmp.size();
        }
    }


    // fs.seekp(len);
    // cout << "ga" << len << '\n';
    // fs << '\n' <<"* [ ] uva" << num << " - " << str;


    // fs.seekp(len,ios::end);
    // for (int i = 0; i < vec.size(); ++i)
    // {
    //     fs << vec[i] << '\n';
    // }

    // fs.close();




    return 0;
}