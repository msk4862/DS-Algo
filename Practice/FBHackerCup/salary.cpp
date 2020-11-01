#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);



void solve() {
    ifstream fileIn;		
    ofstream fileOut;

	fileIn.open("input.txt");
    fileOut.open("output.txt");

    // emp, <manager, level>
    unordered_map<string, pair<string, int>> man;
    // man, <emp, largestLevel>
    unordered_map<string, pair<string, int>> maxL;
    
    string line;
    while (!fileIn.eof() && getline(fileIn, line)) {
        ll i = 0;        
        string emp;

        char* part = strtok((char*) line.c_str(), ",");
        while(part) {
            if(i == 0) {
               emp = string(part);
            }
            else if(i == 2) {
                string manager = string(part+1);
                if(manager.compare("NOBODY")==0) {
                    man[emp] = {emp, 0};
                    maxL[emp] = {emp, 0};
                }
                else {
                    int level = man[manager].second + 1;
                    man[emp] = {man[manager].first, level};

                    string ceo = man[manager].first;
                    if(maxL[ceo].second < level) {
                        maxL[ceo] = {emp, level};
                    }
                }
            }
            i++;
            part = strtok(NULL, ",");
        }
    }

    for(auto com: maxL) {
        fileOut<<com.first<<": "<<com.second.first<<endl;
    }

    fileIn.close();
	fileOut.close();
}

int main() {
    FASTIO
    solve();
    return 0;
}