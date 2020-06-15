#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {
    int t;
    string s;
    
    cin>>t;
    cin.ignore();
    while(t--) {
        getline(cin, s);        
        int pair = 0;
        for (int i = 0; i < s.length()-1; i++) {
            if(s[i] == 'x' && s[i+1] == 'y') {
                pair++;
                i++;
            } else if(s[i] == 'y' && s[i+1] == 'x') {
                pair++;
                i++;
                
            }
        }
        
        cout<<pair<<"\n";
    }
    
    
	return 0;
}
