// Last updated: 12/27/2025, 3:44:08 PM
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for(auto& q : queries) {
            for(int i = q[0]; i <= q[2]; ++i) for(int j = q[1]; j <= q[3]; ++j) matrix[i][j]++;
        }

        return matrix;
    }
};