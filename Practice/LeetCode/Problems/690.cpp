/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int DFS(unordered_map<int, Employee*> m, int id) {
        
        int t=0;
        for(auto s:m[id]->subordinates) {
           t+=DFS(m, s); 
        }

        return m[id]->importance+t;
    }
    
    int getImportance(vector<Employee*> emp, int id) {
        unordered_map<int, Employee*> m;
        
        for(auto e:emp)
            m[e->id]=e;
        
        return DFS(m, id);
            
        // without rec
//         queue<int> q;
//         for(auto e:sub[id]) {
//             cout<<e<<" ";
//             q.push(e);
//         }
//         int res=imp[id];
                
//         while(!q.empty()) {
//             int cur=  q.front();
//             res+=imp[cur];
            
//             q.pop();
//             for(auto e:sub[cur]) {
//                 q.push(e);
//             }
//         }
        
        // return res;
        
    }
};
