// Last updated: 12/27/2025, 3:45:33 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> substring;

        int left = 0, right = 0, maxSum = 0;

        while(right < s.length()) {
            if(!substring.count(s[right])) {
                substring.insert(s[right]);
                maxSum = max(maxSum, right - left + 1);
                right++;
            }
            else {
                substring.erase(s[left]);
                left++;
            }
        }

        return maxSum;
    }
};