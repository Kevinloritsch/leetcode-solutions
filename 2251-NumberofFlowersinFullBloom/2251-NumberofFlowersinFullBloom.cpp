// Last updated: 12/27/2025, 5:18:37 PM
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
11        // runtime O(num flower + numPpl*log(numPpl))
12
13        // we also need to handle ppl being outoforder
14        // to do this, we can sort the array and handle it
15        // push to a hash
16        // then just iterate back over ppl and grab them at the end
17
18        // make array of flower events
19        // i.e. <1, true> means a flower blooms at 1
20        // <6, false> means flower goes away at 6
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
34        int prevP = -1;
35        int index = 0;
36        int lastVal = flowerEvents[flowerEvents.size() - 1].first;
37
38        unordered_map<int, int> table;
39
40        for(auto p : pplCopy) {
41            
42            for(index; index < flowerEvents.size() && flowerEvents[index].first <= p; index++) {
43                if(flowerEvents[index].second) { currActive++; }
44                else { currActive--; }
45            }
46            if(p > lastVal) { table[p] = 0; continue; }
47            table[p] = currActive;
48            
49            prevP = p;
50        }
51
52        vector<int> result;
53        for(auto p : people) {
54            result.push_back(table[p]);
55        }
56
57        return result;
58        
59    }
60};