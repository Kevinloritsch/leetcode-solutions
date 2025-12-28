// Last updated: 12/27/2025, 4:07:00 PM
1class Solution {
2public:
3    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
4        // - is a start
5        // + is a end
6
7        vector<pair<int, int>> points;
8        for(auto building : buildings) {
9            points.push_back({building[0], -building[2]});
10            points.push_back({building[1], building[2]});
11        }
12
13        // it'll go by the first thing, so all the starts and ends in order
14        std::sort(points.begin(), points.end());
15
16        // multiset stores elements in increasing order
17        // last element is greatest
18        // gaslighting a pq but can remove any element
19        multiset<int> pq{0};
20        int ongoingHeight = -1;
21        vector<vector<int>> result;
22
23        for(auto point : points) {
24            if(point.second < 0) pq.insert(-point.second);
25            else pq.erase(pq.find(point.second));
26
27            auto pqTop = *pq.rbegin();
28            // did we pop the ongoingHeight?
29            if(ongoingHeight != pqTop) {
30                ongoingHeight = pqTop;
31                result.push_back({point.first, ongoingHeight});
32            }
33        }
34        return result;
35    }
36};