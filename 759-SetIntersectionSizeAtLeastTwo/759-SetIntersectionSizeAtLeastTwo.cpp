// Last updated: 12/27/2025, 3:44:40 PM
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        
        int a = -1, b = -1;
        int numIntervals = 0;

        for (auto& i : intervals) {

            if (a >= i[0] && b >= i[0]) continue;
            else if (b >= i[0]) {
                numIntervals++;
                a = b;
                b = i[1];
            } else {
                numIntervals += 2;
                a = i[1] - 1;
                b = i[1];
            }
        }

        return numIntervals;
    }
};
