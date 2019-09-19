#include<iostream>
#include<vector>

using namespace std;
int main() {
    
    int t;
    while (cin>>t)
    {   
        int m, n;
        cin >> m>>n;
        for (int i = 0; i < t; i++)
        {
            int x, y;
            cin>>x>>y;

            if (x == m || y == n)
            {
                cout<<"divisa"<<endl;
            }
            else {
                if (x > m)
                {
                    if (y > n)
                    {
                        cout<<"NE"<<endl;
                    }
                    else {
                        cout<<"SE"<<endl;
                    }
                    
                } else {
                    if (y > n)
                    {
                        cout<<"NO"<<endl;
                    }
                    else {
                        cout<<"SO"<<endl;
                    }
                }
                
            }
        }
        
    }
    
}