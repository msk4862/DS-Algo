#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n, p, k;
	cin>>t;
	
	while(t--) {
	    cin>>n>>k;
	    
	    int p[n];
	    
	    int s_sum = 0, a_sum=0;
	    for (int i = 0; i < n; i++) {
	        cin>>p[i];
	        s_sum += p[i];
	        
	        if(p[i] > k) {
	            a_sum += k;
	        } else {
	            a_sum += p[i];
	        }
	       
	    }
	   
	    cout<<s_sum-a_sum<<"\n";

	    
	}
	return 0;
}
