// Last updated: 12/27/2025, 3:44:11 PM
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        prices.push_back(-1);
        long long numInARow = 1;
        long long total = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i - 1] - 1 == prices[i]) numInARow++;
            else {
                total += ((numInARow + 1) * numInARow) / 2;
                numInARow = 1;
            }
        }

        return total;
        
    }
};
/*
4, 3, 2, 1

4
3
2
1
4, 3
3, 2
2, 1
4, 3, 2
3, 2, 1
4, 3, 2, 1

4
*/