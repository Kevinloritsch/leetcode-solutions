// Last updated: 12/27/2025, 3:45:20 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return dpClimbStairs(n, dp);
    }

    int dpClimbStairs(int n, vector<int>& dp) {
        if(dp[n] != -1) return dp[n];

        if(n<=0) return 1;
        if(n==1) return 1; 
        // if(n==2) return 2;

        return dp[n] = dpClimbStairs(n-1, dp) + dpClimbStairs(n-2, dp);
    }
};