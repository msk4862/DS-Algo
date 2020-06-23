class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) { 
            vector<int> p{1};
            return p;
        }
        vector<int> pre = getRow(rowIndex-1);
        vector<int> cur(rowIndex+1);
        
        int preIndex= 0;
        for(int i = 0; i < cur.size(); ++i) {
            if(i == 0 or i == rowIndex) cur[i] = 1;
            
            else {
                cur[i] = pre[preIndex]+pre[preIndex+1];
                preIndex+=1;
            }
        }
        
        return cur;
    }
};