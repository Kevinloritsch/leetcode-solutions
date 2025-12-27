// Last updated: 12/27/2025, 3:44:42 PM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        floodFill(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    void floodFill(vector<vector<int>>& image, int sr, int sc, int color, int initialVal) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[sr].size() || image[sr][sc] != initialVal) return;

        image[sr][sc] = color;

        floodFill(image, sr + 1, sc, color, initialVal);
        floodFill(image, sr - 1, sc, color, initialVal);
        floodFill(image, sr, sc + 1, color, initialVal);
        floodFill(image, sr, sc - 1, color, initialVal);
    }
};