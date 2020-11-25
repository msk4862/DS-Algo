class Solution {
public:
    bool visited[50001] = {0};
    
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start  >= arr.size()) return false;
        
        if(visited[start]) return false;
        
        visited[start] = 1;
        if(arr[start] == 0) return true;
        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
        
    }
};
