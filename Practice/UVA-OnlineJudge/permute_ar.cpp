#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    ll t, n;

    cin>>t;
    cin.ignore();

    while (t--)
    {   
        string elem;
        getline(cin, elem);
        getline(cin, elem);
        vector<int> index;
        
        elem += " ";
        string num = "";
        for(int i = 0; i < elem.length(); ++i) {
            
            if (elem[i] == ' ') {
                index.push_back(stoi(num));
                num = "";
                
            } else {
                
                num += elem[i]; 
            }
        }
        
        vector<float> arr(elem.length());

        for (int i = 0; i < index.size(); i++)
        {
            cin>>arr[index[i]-1];
        }
        
        
        
        for (int i = 0; i < index.size(); i++)
        {
            cout<<arr[i]<<"\n";
        }
        cout<<"\n";
    }
    

    return 0;
}