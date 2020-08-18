class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> tar;
        unordered_map<char, int> mag;
        
        for(int i = 0; i < ransomNote.length(); ++i) {
            if(tar.find(ransomNote[i]) != tar.end())
                tar[ransomNote[i]]++;
            else
                tar[ransomNote[i]] = 1; 
        }
        
        
        for(int i = 0; i < magazine.length(); ++i) {
            if(mag.find(magazine[i]) != mag.end())
                mag[magazine[i]]++;
            else
                mag[magazine[i]] = 1; 
        }
        
        for(auto t:tar) {
            if(mag[t.first] < t.second)
                return false;
        }
        
        return true;
    }
};