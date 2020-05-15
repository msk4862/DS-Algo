#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    vector< vector<char> > park(n, vector<char> (m));
    int strength = s;
    bool blocked = false, possible = true;


    for (int i = 0; i < n; i++)
    {
        blocked=false;
        if(!possible) {
            break;
        }
        for (int j = 0; j < m; j++)
        {
            cin>>park[i][j];

            if(!blocked) {
                if(park[i][j] == '.') {
                    strength -= 3;
                } else if(park[i][j] == '*') {
                    strength += 4;
                }
                else if(park[i][j]== '#') {
                    blocked=true;
                }

				if(j==m-1) {
					strength+=1;
				}

                if(strength <= k) {
                    possible=false;
                    break;
                }
            }
            
        }
        
    }

    if(possible ) {
        //adding n for end rows
        cout<<"Yes\n"<<strength;
    } else {
        cout<<"No";
    }
    
}