#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// (b-a)*m = p-q
ll mulFunc(ll a, ll b, ll p, ll q) {
	if(b!= a && (q-p)%(b-a)==0)
		return (q-p)/(b-a);
	else 
		return 1;
}

bool equal(ll s[], ll d[]) {
	for (int i = 0; i < 3; ++i) 
	    if(s[i]!=d[i]) 
	        return false;
	return true;
}

int best;
void minopr(ll s[], ll d[], int opr) {
    
    if(opr >= best) {
    	return;
    }
    
    if(equal(s, d)) {
        best = min(opr, best);
        return;
    }
    if(opr >= 2) {
    	return;
    }
    
    
    unordered_set<ll> add;

    // all possible additions
    add.insert(d[0]-s[0]);
    add.insert(d[1]-s[1]);
    add.insert(d[2]-s[2]);
    

    // all possible multiplications
	unordered_set<ll> mul;
	for (int i = 0; i < 3; ++i) {
		if(s[i] != 0 && d[i]%s[i]==0)
				mul.insert(d[i]/s[i]);
	}
    mul.insert(mulFunc(s[0], s[1], d[0], d[1]));
    mul.insert(mulFunc(s[1], s[2], d[1], d[2]));
    mul.insert(mulFunc(s[0], s[2], d[0], d[2]));
    mul.insert(0);

    // applying operations on all permutation of numbers

    // for generating subset(using bit manipulation)
    for (int mask = 1; mask <= 7; ++mask) {	
    	vector<int> subset;
    	// checking which bits are set (to generate  subset)
    	for (int i = 0; i < 3; ++i) {
    		if(mask&(1<<i))
				subset.push_back(i);
    	}
        
        // for(auto x: subset) cout<<x<<" ";
        // cout<<endl;
    	//applying addition on subset
    	for(auto op : add) {
    		ll newSource[3];
    		for (int i = 0; i < 3; ++i) newSource[i] = s[i];

    		for(auto e: subset) newSource[e] += op;
    // 		cout<<newSource[0]<<" "<<newSource[1]<<" "<<newSource[2];
    		minopr(newSource, d, opr+1);
    	}

    	//applying multiplication on subset
    	for(auto op : mul) {
    		ll newSource[3];
    		for (int i = 0; i < 3; ++i) newSource[i] = s[i];

    		for(auto e: subset) newSource[e] *= op;
    		minopr(newSource, d, opr+1);
    	}
    }

}


int main() {
    int t;
    cin>>t;
    while(t--) {
        ll s[3], d[3];
        for (int i = 0; i < 3; i++) {
            cin>>s[i];
        } 

        for (int i = 0; i < 3; i++) {
            cin>>d[i];
        }

        best = 3;
        minopr(s, d, 0);
        cout<<best<<"\n";
    }
}