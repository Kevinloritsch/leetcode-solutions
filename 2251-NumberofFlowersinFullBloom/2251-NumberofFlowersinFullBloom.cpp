// Last updated: 12/27/2025, 5:22:28 PM
1class Solution {
2public:
3    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
4
5        // we loop through ppl
6        // at first person, say they arrive at 1
7        // then i go through flower array till i reach those that start/end at one
8        // hash them to grab when they pop in or out
9        // keep a global count
10        // push back the global count
11        // runtime O(numFlwr*log(numFlwr) + numPpl*log(numPpl))
12
13        // we also need to handle ppl being outoforder
14        // to do this, we can sort the array and handle it
15        // push to a hash
16        // then just iterate back over ppl and grab them at the end
17
18        // make array of flower events
19        // i.e. <1, true> means a flower blooms at 1
20        // <7, false> means flower goes away at 7 (+ 1 since the flower stays through 6)
21        vector<pair<int, bool>> flowerEvents;
22
23        for(int i = 0; i < flowers.size(); ++i) {
24            flowerEvents.push_back({flowers[i][0], true});
25            flowerEvents.push_back({flowers[i][1] + 1, false});
26        }
27
28        std::sort(flowerEvents.begin(), flowerEvents.end());
29
30        vector<int> pplCopy = people;
31        std::sort(pplCopy.begin(), pplCopy.end());
32
33        int currActive = 0;
34        int index = 0;
35        int lastVal = flowerEvents[flowerEvents.size() - 1].first;
36
37        unordered_map<int, int> table;
38
39        for(auto p : pplCopy) { 
40            for(index; index < flowerEvents.size() && flowerEvents[index].first <= p; index++) {
41                if(flowerEvents[index].second) currActive++;
42                else currActive--;
43            }
44            table[p] = currActive; 
45        }
46
47        vector<int> result;
48        for(auto p : people) {
49            result.push_back(table[p]);
50        }
51
52        return result;
53        
54    }
55};