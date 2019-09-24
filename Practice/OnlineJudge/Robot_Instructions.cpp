#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        string ins;
        vector<int> ins_list;
        
        cin.ignore();
        for (size_t i = 0; i < n; i++)
        {
            getline(cin, ins);
            if (ins[0] == 'L')
            {
                ins_list.push_back(-1);
            } else if(ins[0] == 'R') {
                ins_list.push_back(1);
            } else {
                int op =  stoi(ins.substr(ins.rfind(" ")+1));
                ins_list.push_back( ins_list[ op - 1 ]);
            
            }
            
        }
    
        int final_pos = 0;
        for(int i = 0;i < n;++i) {
            final_pos += ins_list[i];
        }

        cout<<final_pos<<endl;
    }
}