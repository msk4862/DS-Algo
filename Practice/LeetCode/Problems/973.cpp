class Point {
    
    public:
    
    vector<int> cor;
    int dist;
    
    Point(vector<int> p, int d) {
        cor = p;
        dist = d;
    }
};

class Comp {
    public:
        bool operator() (Point* p1, Point* p2) {
            return p1->dist > p2->dist;
        }
};

class Solution {
public:

    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Point*, vector<Point*>, Comp> dist;
        
        for(auto p: points) {
            long d = pow(p[0], 2) + pow(p[1], 2);
            Point* cur = new Point(p, d); 
            dist.push(cur);
        }
        
        vector<vector<int>> res;
        for(int i = 0; i < K; ++i) {
            int d = dist.top()->dist;
            cout<<d<<" ";
            res.push_back(dist.top()->cor);
            dist.pop();
        }
        
        return res;
    }
};
