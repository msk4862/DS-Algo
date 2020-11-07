#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

string trim(string s)
{
    string space = " \t";
    int begin = s.find_first_not_of(space);
    int end = s.find_last_not_of(space);
    cout<<s.substr(begin, end);

    return s.substr(begin, end);
}

string standardize(string s) {
    s = trim(s);
    // remove extra spaces 
    s = regex_replace(s, regex(" +"), " ");
    return s;
}


int findAlmostDup(string str1, string str2) 
{ 
	int len1 = str1.length(); 
	int len2 = str2.length(); 
	int dp[2][len1 + 1]; 

	memset(dp, 0, sizeof(dp)); 

	for (int i = 0; i < len1+1; i++) 
		dp[0][i] = i; 

	for (int i = 1; i < len2+1; i++) { 
		for (int j = 0; j < len1+1; j++) { 
			if (j == 0) dp[i % 2][j] = i; 
			else if (str1[j - 1] == str2[i - 1]) { 
				dp[i % 2][j] = dp[(i - 1) % 2][j - 1]; 
			} 
			else { 
				dp[i % 2][j] = min(dp[(i - 1) % 2][j - 1], min(dp[i % 2][j - 1], dp[(i - 1) % 2][j])) + 1; 
            } 
		} 
	} 
	return dp[len2 % 2][len1]; 
} 


void solve() {
    ifstream fileIn;		
    ofstream fileOut;

	fileIn.open("input.txt");
    fileOut.open("output.txt");

    ll dups = 0;
    vector<pair<vector<string>, bool>> customer;

    string line;
    vector<string> cust;
    while (!fileIn.eof() && getline(fileIn, line)) {
        if(line.compare("--") == 0 && cust.size() == 3) {
            bool dup = false;  
            cout<<cust[0]<<"  ";
            for(int i = 0; i < customer.size(); ++i) {
                // compare using comp first

                int mis1 = findAlmostDup(customer[i].first[0], cust[0]);
                // not a duplicate
                if(mis1 > 1) {
                    continue;
                }
                int mis2 = findAlmostDup(customer[i].first[1], cust[1]);
                if(mis2 > 1) {
                    continue;
                }
                int mis3 = findAlmostDup(customer[i].first[2], cust[2]);
                if(mis3 > 1) {
                    continue;
                }

                // duplicate
                if(mis1 + mis2 +mis3 <= 2) {
                    // cout<<"duppp "<<customer[i].first[0]<<endl;

                    dup = true;
                    dups += customer[i].second? 1 : 2;
                    customer[i].second = 1;
                    break;
                }
            }            
            if(!dup)  customer.push_back({cust, 0});

            cust.clear();
        }
        else if(line.compare("--") == 0 && cust.size() != 3) cust.clear();
        else cust.push_back(standardize(line));
    }

    if(cust.size() == 3) {
    // for last 
    for(int i = 0; i < customer.size(); ++i) {
        int mis1 = findAlmostDup(customer[i].first[0], cust[0]);
        // not a duplicate
        if(mis1 > 1) {
            continue;
        }
        int mis2 = findAlmostDup(customer[i].first[1], cust[1]);
        if(mis2 > 1) {
            continue;
        }
        int mis3 = findAlmostDup(customer[i].first[2], cust[2]);
        if(mis3 > 1) {
            continue;
        }

        // duplicate
        if(mis1 + mis2 +mis3 <= 2) {
            dups += customer[i].second? 1 : 2;
            customer[i].second = 1;
            break;
        }
    }
    }

    fileOut<<dups;

    fileIn.close();
	fileOut.close();
}

int main() {
    FASTIO
    solve();
    return 0;
}