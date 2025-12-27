// Last updated: 12/27/2025, 3:45:05 PM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> toReturn(numRows);

        toReturn[0].resize(1);
        toReturn[0][0] = 1;

        if(numRows > 1) {
            toReturn[1].resize(2);
            toReturn[1][0] = 1;
            toReturn[1][1] = 1;

            for(int i = 1; i < numRows; ++i) {
                toReturn[i].resize(i+1);
                toReturn[i][0] = 1;
                toReturn[i][i] = 1;
                for(int j = 1; j < i; ++j) {
                    toReturn[i][j] = toReturn[i-1][j-1] + toReturn[i-1][j];
                }
            }
        }

        return toReturn;
    }
};