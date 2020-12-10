class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        
        int diff = 1;
        for(int i = 1; i < arr.size(); ++i) {
            int curDiff = arr[i] - arr[i-1];
            
            // equal values
            if(curDiff == 0) return false;
            // decrement start 
            // i !=1 to avoid case of absence of uphill
            if(i != 1 && diff > 0 && curDiff < 0) diff = -1;
            
            else if(curDiff < 0 && diff > 0) return false;
            else if(curDiff > 0 && diff < 0) return false;
        
        }
        
        if(diff < 0) return true;
        // there is no downhill part
        return false;
    }
};
