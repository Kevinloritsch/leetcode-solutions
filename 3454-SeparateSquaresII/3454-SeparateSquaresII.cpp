// Last updated: 1/14/2026, 3:38:12 PM
1class Solution {
2public:
3    double separateSquares(vector<vector<int>>& squares) {
4        struct Event {
5            int y;
6            int type; // +1 for START of square, -1 for END of square
7            int xStart;
8            int xEnd;
9
10            // Sort events primarily by Y coordinate
11            bool operator<(const Event& other) const {
12                return y < other.y;
13            }
14        };
15
16        struct Strip {
17            int y;
18            int height;
19            double unionWidth;
20        };
21
22        vector<Event> sweepEvents;
23        for (const auto& sq : squares) {
24            int x = sq[0];
25            int y = sq[1];
26            int l = sq[2];
27            sweepEvents.push_back({y, 1, x, x + l});
28            sweepEvents.push_back({y + l, -1, x, x + l});
29        }
30
31        sort(sweepEvents.begin(), sweepEvents.end());
32
33        vector<pair<int, int>> activeIntervals;
34        vector<Strip> processedStrips;
35        double totalArea = 0;
36        int prevY = sweepEvents[0].y;
37
38        for (const auto& event : sweepEvents) {
39            // Process the strip formed between the previous event and current event
40            if (event.y > prevY) {
41                double width = getUnionWidth(activeIntervals);
42                int height = event.y - prevY;
43                
44                if (width > 0) {
45                    processedStrips.push_back({prevY, height, width});
46                    totalArea += (double)height * width;
47                }
48            }
49
50            // Update active intervals based on event type
51            if (event.type == 1) {
52                activeIntervals.push_back({event.xStart, event.xEnd});
53            } else {
54                // Find and remove the interval. 
55                // We iterate to find the specific interval to remove one instance.
56                for (auto it = activeIntervals.begin(); it != activeIntervals.end(); ++it) {
57                    if (it->first == event.xStart && it->second == event.xEnd) {
58                        activeIntervals.erase(it);
59                        break;
60                    }
61                }
62            }
63            prevY = event.y;
64        }
65
66        // Second Pass: Find the exact cut line
67        double targetArea = totalArea / 2.0;
68        double accumulatedArea = 0;
69
70        for (const auto& strip : processedStrips) {
71            double stripArea = strip.height * strip.unionWidth;
72
73            if (accumulatedArea + stripArea >= targetArea) {
74                double areaNeeded = targetArea - accumulatedArea;
75                return strip.y + (areaNeeded / strip.unionWidth);
76            }
77            accumulatedArea += stripArea;
78        }
79
80        return 0.0;
81    }
82
83private:
84    // Helper to calculate the length of the union of intervals
85    double getUnionWidth(vector<pair<int, int>> intervals) {
86        if (intervals.empty()) return 0;
87        
88        sort(intervals.begin(), intervals.end());
89
90        double unionLength = 0;
91        double currentEnd = -1e18; // Negative infinity
92
93        for (const auto& interval : intervals) {
94            double start = interval.first;
95            double end = interval.second;
96
97            if (start >= currentEnd) {
98                // No overlap with previous, add full length
99                unionLength += (end - start);
100                currentEnd = end;
101            } else if (end > currentEnd) {
102                // Partial overlap, extend the current end
103                unionLength += (end - currentEnd);
104                currentEnd = end;
105            }
106        }
107        return unionLength;
108    }
109};