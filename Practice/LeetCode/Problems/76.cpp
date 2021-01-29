class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tar_mp, found_mp;
        
        for(char s: t) tar_mp[s]++;
        
        int s_size = s.size();
        int t_size = t.size();
        int start = 0, end = 0;
        int matchCount = 0;
        
        // finding a initial window
        while(matchCount < t_size && end < s_size) {
            char cur = s[end];            
            if(tar_mp[cur]) {
                // if target count is not yet reached
                if(found_mp[cur] < tar_mp[cur]) matchCount++;       
                found_mp[cur]++;                
            }
            end++;
        }
        
        if(matchCount < t_size) return "";
        
        pair<int, int> min_wind = {start, --end};
        while(end < s_size) {  
            // cout<<start<<" "<<end<<endl;
            
            // shrinking window
            if(matchCount == t_size) {
                // updaing window if smaller one found
                if((min_wind.second-min_wind.first+1)>(end-start+1))
                    min_wind ={start, end};
               
                char cur = s[start]; 
                if(tar_mp[cur]) {
                    // if target count is decrementing
                    if(found_mp[cur] <= tar_mp[cur]) matchCount--;       
                    found_mp[cur]--;                
                }
                start++;
            }
            // expanding window
            else {
                end++;
                if(end >= s_size) break;
                
                char cur = s[end];
                if(tar_mp[cur]) {
                    if(found_mp[cur] < tar_mp[cur]) matchCount++;       
                    found_mp[cur]++;                
                }
            }
        }
        
        return s.substr(min_wind.first, min_wind.second-min_wind.first+1);
    }
};
