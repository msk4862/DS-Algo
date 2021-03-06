#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    stack<char> expression;

    for(int i= 0; i< str.length(); ++i) {
    
        if(str[i] == '(' || str[i] == '[' || str[i]== '{')
            expression.push(str[i]);
        else if(str[i] == ')' || str[i] == ']' || str[i]== '}') {
            if (expression.empty()) {
                //in closing
                cout<<i+1<<"\n";
                return 0;
            }
            char last = expression.top();
            if ((str[i] == ')' && last=='(') || (str[i]=='}' && last=='{') || (str[i]==']' && last=='['))
                expression.pop();
            else {
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    if(expression.empty()) {
        cout<<"Success\n";
    } else {
        cout<<"1\n";
    }
}   