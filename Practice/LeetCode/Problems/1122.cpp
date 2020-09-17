unordered_map<int, int> m;

class Solution {
public:
    
    static bool comp(int a, int b) {
        if(m[a] && m[b])
        return m[a]<m[b];
        else if(m[a]) 
            return true;
        else if(m[b])
            return false;
        else return a<b;
    }
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        m.clear();
        
        for(int i = 0; i < arr2.size(); ++i) {
            m[arr2[i]] = i+1;
        }
        
        
        sort(arr1.begin(), arr1.end(), comp);
        return arr1;
    }
};
