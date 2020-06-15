#include <iostream>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    
    while(t--) {
        int N;
        cin>>N;
        
        int M[N][N];
        int num=1;
        int alt =1;
        
        int j;
        for (int i = 0; i < N; i++) {
            if(alt) {
                for (int j = 0; j < N; j++) {
                    M[i][j] = num;
                    num++;
                }
                alt=0;
            }
            else {
                for (int j = N-1; j >=0; j--) {
                    M[i][j] = num;
                    num++;
                    
                }
                
                alt =1;
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout<<M[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
	return 0;
}
