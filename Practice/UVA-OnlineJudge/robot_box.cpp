#include<bits/stdc++.h>
using namespace std;

int main() {
    string command, command2;
    int a, b;
    
    int n;
    cin>>n;

    vector<vector<int> > ar(n, vector<int> (n, -1));
    for (int i = 0; i < ar.size(); i++)
    {   // setting initial pos
        ar[i][0] = i;
    }
    

    cin>>command;
    while (command != "quit")
    {   
        cin>>a>>command2>>b;

        if(a == b)
            continue;

        int pos_a[2], pos_b[2];
        for (int i = 0; i < ar.size(); i++)
        {
            for (int j = 0; j < ar.size(); j++)
            {
                if(ar[i][j] == -1) {
                    break;
                } else if(ar[i][j] == a){
                    pos_a[0] = i;
                    pos_a[1] = j;
                }
                else if(ar[i][j] == b){
                    pos_b[0] = i;
                    pos_b[1] = j;
                }
            }
        }
        
        if (pos_a[0] == pos_b[0]) //same row
            continue;
        int row;
        if(command == "move") {
            //remove everything on top of a and b
            if(command2 == "onto") {
                row = pos_a[0];

                if(pos_a[1] + 1 < n) {
                    for (int i = pos_a[1]+1; ar[row][i] != -1; i++)
                    {
                        ar[ar[row][i]][0] = ar[row][i];
                        ar[row][i] = -1;
                    }
                }
                

                row = pos_b[0];
            
                if(pos_b[1] + 1 < n) {
                    for (int i = pos_b[1]+1; ar[row][i] != -1; i++)
                    {
                        ar[ar[row][i]][0] = ar[row][i];
                        ar[row][i] = -1;
                    }
                }

                ar[pos_b[0]][pos_b[1]+1] = a;
                ar[pos_a[0]][pos_a[1]] = -1;
                
            } else {
                //remove everything on top of a 
                row = pos_a[0];

                if(pos_a[1] + 1 < n) {
                    for (int i = pos_a[1]+1; ar[row][i] != -1; i++)
                    {
                        ar[ar[row][i]][0] = ar[row][i];
                        ar[row][i] = -1;
                    }
                }

                ar[pos_b[0]][pos_b[1]+1] = a;
                ar[pos_a[0]][pos_a[1]] = -1;
            }
        } else {
            if(command2 == "onto") {
                row = pos_b[0];

                if(pos_b[1] + 1 < n) {
                    for (int i = pos_b[1]+1; ar[row][i] != -1; i++)
                    {
                        ar[ar[row][i]][0] = ar[row][i];
                        ar[row][i] = -1;
                    }

                    
                ar[pos_b[0]][pos_b[1]+1] = a;
                ar[pos_a[0]][pos_a[1]] = -1;
                }
            } else {
                
            }
        }
        
        cin>>command;
        
    }
    
    for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = 0; j < n; j++) {
			if (ar[i][j] == -1) break;
			cout << " " << ar[i][j];
		}
		cout << endl;
	}

    accumulate()
    
}