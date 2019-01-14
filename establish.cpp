#include <bits/stdc++.h>

using namespace std;

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
            cout << problem << '\n';
            if (num < problem)
            {
                fs << "\n" << "* [ ] uva" << num << " - " << str << '\n';
                flag = 1;
                break;   
            }
        }
        else
            continue;
    }
    if (!flag)
    {
        fs << "\n" << "* [ ] uva" << num << " - " << str;
    }





    return 0;
}