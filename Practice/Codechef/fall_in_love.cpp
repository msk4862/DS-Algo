#include <iostream>
#include<iomanip>
using namespace std;

#define PI 3.14159
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	int n;
	int sum=0;
	while(t--) {
        sum = 0;
	    cin>>n;
	    
	    int a;
	    for(int i = 0;  i<n;++i) {
	        cin>>a;
	        sum+= a;
	    }
	    
	    double res= (sum)/(10.0*n*PI);
	    cout<<setprecision(15);
	    cout<<res<<endl;
	    
	}
	
	return 0;
}
