#include <bits/stdc++.h>

using namespace std;

struct Record {
    string name;
    int score;
    friend istream& operator>>(istream& is, Record& r)       { return is >> r.name         >> r.score; }
    friend ostream& operator<<(ostream& os, Record const& r) { return os << r.name << "\t" << r.score; }

    bool operator<(Record const& other) const {
        return other.score < score;
    }
};

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



    ifstream ifs("README.md");
    string tmp;
    while(getline(ifs,tmp))
    {
        for (int i = 0; i < tmp.size(); ++i)
        {
            
        }
    }
    vector <Record> vec;

    vec.push((Record){str,num});

    sort(vec.begin(),vec.end());

    ofstream ofs("")




    return 0;
}