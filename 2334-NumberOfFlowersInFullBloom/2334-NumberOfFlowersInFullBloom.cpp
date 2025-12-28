// Last updated: 12/28/2025, 3:18:13 PM
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        // we loop through ppl
        // at first person, say they arrive at 1
        // then i go through flower array till i reach those that start/end at one
        // hash them to grab when they pop in or out
        // keep a global count
        // push back the global count
        // runtime O(numFlwr*log(numFlwr) + numPpl*log(numPpl))

        // we also need to handle ppl being outoforder
        // to do this, we can sort the array and handle it
        // push to a hash
        // then just iterate back over ppl and grab them at the end

        // make array of flower events
        // i.e. <1, true> means a flower blooms at 1
        // <7, false> means flower goes away at 7 (+ 1 since the flower stays through 6)
        vector<pair<int, bool>> flowerEvents;

        for(int i = 0; i < flowers.size(); ++i) {
            flowerEvents.push_back({flowers[i][0], true});
            flowerEvents.push_back({flowers[i][1] + 1, false});
        }

        std::sort(flowerEvents.begin(), flowerEvents.end());

        vector<int> pplCopy = people;
        std::sort(pplCopy.begin(), pplCopy.end());

        int currActive = 0;
        int index = 0;
        int lastVal = flowerEvents[flowerEvents.size() - 1].first;

        unordered_map<int, int> table;

        for(auto p : pplCopy) { 
            for(index; index < flowerEvents.size() && flowerEvents[index].first <= p; index++) {
                if(flowerEvents[index].second) currActive++;
                else currActive--;
            }
            table[p] = currActive; 
        }

        vector<int> result;
        for(auto p : people) {
            result.push_back(table[p]);
        }

        return result;
        
    }
};