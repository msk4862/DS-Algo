class Solution {
public:
    void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int newColor, int startColor) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != startColor) return;
        
        image[sr][sc] = newColor;
        floodFillHelper(image, sr-1, sc, newColor, startColor);
        floodFillHelper(image, sr, sc-1, newColor, startColor);
        floodFillHelper(image, sr+1, sc, newColor, startColor);
        floodFillHelper(image, sr, sc+1, newColor, startColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc]) return image;
        
        floodFillHelper(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
