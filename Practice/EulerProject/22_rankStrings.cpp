#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long rankStrings(vector<string> &s) {
    sort(s.begin(), s.end());
    
    long long score = 0;

    string word;
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        word = s[i];

        sum = 0;
        for (int j = 0; j < word.length(); j++)
        {
            sum +=  (word[j]-'A'+1);
        }
        
        score += sum*(i+1);

    }

    return score;
    
}

int main() {    
    vector<string> test1 {"THIS", "IS", "ONLY", "A", "TEST"};


    vector<string> t2 {"I", "REPEAT", "THIS", "IS", "ONLY", "A", "TEST"};

    
    cout<<rankStrings(test1);
    return 0;

}
