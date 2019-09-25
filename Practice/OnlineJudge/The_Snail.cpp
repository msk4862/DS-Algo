#include<iostream>

using namespace std;

int main() {
    int H, D, S, F;

    while(cin>>H>>D>>S>>F && (H != 0)) {
        
        float cur = 0, dist_c = D;
        int day = 0;
        
        float decay = (dist_c*F)/100.0;
        do
        {
            day += 1;
            
            if (day ==1)
            {
                cur += dist_c;
            } else {
                dist_c -= decay;
                if(dist_c <0) {
                    dist_c = 0;
                }
                cur += dist_c;
            }
            
            if(cur > H)
                break;
            cur -= S;
            
        }while(cur >= 0);
        
        if (cur > H)
        {
            cout<<"success on day "<<day<<endl;
        } else {
            cout<<"failure on day "<<day<<endl;
        }
        
    }
}