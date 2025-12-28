// Last updated: 12/27/2025, 3:44:14 PM
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        if(changed.size() % 2 == 1) return {};

        unordered_map<int, int> tracker;

        for(auto x : changed) {
            tracker[x]++;
        }

        std::sort(changed.begin(), changed.end());

        vector<int> answ;

        for(auto x : changed) {
           if (tracker[x] == 0) continue;

            if (tracker[2 * x] == 0) return {};

            // special case: zero must be paired with zero
            if (x == 0 && tracker[x] < 2) return {};
            
            tracker[x]--;
            tracker[x * 2]--;
            answ.push_back(x);
            
        }


        return answ.size() == changed.size() / 2 ? answ : vector<int>{};

        
    }
};