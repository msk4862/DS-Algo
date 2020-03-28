#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, t = 1;

    cin>>n;
    while (n != 0)
    {   
        int e, sum = 0;
        vector <int> height;
        for (int i = 0; i < n; i++)
        {
            cin>>e;
            height.push_back(e);
            sum += e;
        }

        int size = sum/n;

        int mov1 = 0, mov2 = 0;
        for (int i = 0; i < n; i++)
        {
            if(height[i] < size) {
                mov1 += abs(height[i]-size); 
            }

        }
        
        
        cout<<"Set #"<<t++<<"\nThe minimum number of moves is "<<mov1<<".\n\n";

        cin>>n;
    }
    
}