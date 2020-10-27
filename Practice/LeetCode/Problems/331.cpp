class Solution {
public:
    
    bool isValidSerialization(string preorder) {        
        
        int op_deg = 1;
        // node => more two outdegree + (-1 degree of parent)
        // null => degree-1
        
        char* token = strtok((char *) preorder.c_str(), ",");
        while(token!=NULL) {
            if(--op_deg < 0) return false;
            if(strcmp(token, "#")) op_deg+=2;
            token = strtok(NULL, ",");
        }
                
        return op_deg == 0;
    }
};
