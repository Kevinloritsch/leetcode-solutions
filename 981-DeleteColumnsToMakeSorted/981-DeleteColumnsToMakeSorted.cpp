// Last updated: 12/27/2025, 3:44:34 PM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        char prev = 'a';
        int counter = 0;
        for(int i = 0; i < strs[0].size(); ++i) {
            prev = 'a';
            for(auto& s : strs) {
                if(s[i] < prev) { counter++; break; }
                prev = s[i];
            }
        }

        return counter;
        
        
    }
};