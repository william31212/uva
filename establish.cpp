#include <bits/stdc++.h>

using namespace std;

struct Record {
    string name;
    char aks;
    int score;

    bool operator < (Record const& other) const {
        return other.score > score;
    }
};

int main()
{
    vector <Record> vec;

    vec.clear();
    int num;
    string str;
    char isok;
    printf("Enter the question number:\n");
    cin >> num;
    printf("Enter the question name:\n");
    cin >> str;
    getchar();
    printf("isok? (Y/N)\n");
    cin >> isok;




    ifstream ifs("README.md");
    string tmp;
    int j = 0;
    while(getline(ifs,tmp))
    {
        char num_char[100];
        char aks_tmp;
        int k = 0;
        int string_index = 0;

        if (tmp[6] == 'u' && tmp[7] == 'v' && tmp[8] == 'a')
        {
            if (tmp[3] == 'x')
            {
                aks_tmp = 'x';
            }
            else
            {
                aks_tmp = ' ';
            }
            for (j = 9; tmp[j] != ' '; ++j)
            {
                num_char[k] = tmp[j];
                k++;
            }
            string str_tmp;
            for (int s = j + 3; s < tmp.size(); ++s)
            {
                str_tmp += tmp[s];
            }

            int number = atoi(num_char);

            vec.push_back((Record){str_tmp,aks_tmp,number});
        }
        else
            continue;


    }

    if (isok == 'y' || isok == 'Y')
       vec.push_back((Record){str,'x',num});
    else if (isok == 'n' || isok == 'N')
       vec.push_back((Record){str,' ',num});
    else
    {
        printf("??????fuckyou what are you doing???????\n");
        return 0;
    }



    sort(vec.begin(),vec.end());

    ofstream ofs("README.md");

    ofs << "# UVA" << '\n';
    ofs << '\n';
    for (int i = 0; i < vec.size(); ++i)
    {
        ofs << "* [" << vec[i].aks << "] uva" << vec[i].score << " - " << vec[i].name << '\n';
    }




    return 0;
}