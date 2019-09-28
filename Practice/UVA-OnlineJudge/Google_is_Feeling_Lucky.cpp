#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct websites
{
    string name;
    int rel;
};

bool compareRel(websites w1, websites w2) {
    return (w1.rel > w2.rel);
}

int main() {
    int t;
    cin>>t;

    int test =1;
    websites web[10];
    while(test <= t) {
        for (size_t i = 0; i < 10; i++)
        {
            cin>>web[i].name;
            cin>>web[i].rel;
        }
        
        sort(web, web+10, compareRel);
        cout<<"Case #"<<test<<":"<<endl;
        cout<<web[0].name<<endl;
        int j =1;
        while (web[j].rel == web[0].rel  && j < 10)
        {
            cout<<web[j].name<<endl;
            j++;
        }
        
        test++;
    }
}
