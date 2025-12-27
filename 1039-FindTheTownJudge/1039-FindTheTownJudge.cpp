// Last updated: 12/27/2025, 3:44:32 PM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n);
        vector<int> out(n);

        for(auto & i : trust) {
            ++in[i[1]-1];
            ++out[i[0]-1];
        }

        for(int i = 0; i < n; ++i) {
            if(in[i] == n-1 && out[i] == 0) return i+1;
        }

        return -1;

    }
};