// Last updated: 12/27/2025, 3:44:23 PM
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> canReach(arr.size(), false);

        return helperCanReach(arr, canReach, start);

    }

    bool helperCanReach(vector<int>& arr, vector<bool>& canReach, int start) {
        if(canReach[start]) return false;

        canReach[start] = true;

        if (arr[start] == 0) return true;

        bool result = false;

       if(start + arr[start] < arr.size()) {
            if(helperCanReach(arr, canReach, start + arr[start])) return true;
        }

        if(start - arr[start] >= 0) {
            if(helperCanReach(arr, canReach, start - arr[start])) return true;
        }

        return false;
    }
};