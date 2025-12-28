// Last updated: 12/28/2025, 3:18:29 PM
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int topRow = 0;
        int topCol = 0;

        int count = 0;

        for(int i = grid.size() - 1; i >= topRow; --i) {
            for(int j = grid[0].size() - 1; j >= topCol; --j) {
                if(grid[i][j] >= 0) {
                    topCol = j;
                }
                else ++count;
            }
        }

        return count;
        
    }
};