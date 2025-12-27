// Last updated: 12/27/2025, 3:45:18 PM
class Solution {
public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return dpMinDistance(dp, word1, word2, 0, 0);
    }

    int dpMinDistance(vector<vector<int>>& dp, string& word1, string& word2, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        if(i >= word1.length()) return word2.length() - j;
        if(j >= word2.length()) return word1.length() - i;
        if(word1[i] == word2[j]) return dp[i][j] = dpMinDistance(dp, word1, word2, i+1, j+1);

        return dp[i][j] = min(min(dpMinDistance(dp, word1, word2, i+1, j), dpMinDistance(dp, word1, word2, i+1, j+1)), dpMinDistance(dp, word1, word2, i, j+1)) + 1;
    }
};