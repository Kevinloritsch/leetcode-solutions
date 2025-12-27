// Last updated: 12/27/2025, 3:44:33 PM
#include <bits/stdc++.h>

class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return dpFib(n, dp);
        
    }

    int dpFib(int n, vector<int>& dp) {
        if(dp[n] != -1) return dp[n];

        if(n==0) return 0;
        if(n==1) return 1;

        return dp[n] = dpFib(n-1, dp) + dpFib(n-2, dp);
    }
};