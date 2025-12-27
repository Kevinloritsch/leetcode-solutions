// Last updated: 12/27/2025, 3:45:32 PM
using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    int romanToInt(string s) {

        vector <pair<char, int>> roman;
        roman.push_back({'I', 1});
        roman.push_back({'V', 5});
        roman.push_back({'X', 10});
        roman.push_back({'L', 50});
        roman.push_back({'C', 100});
        roman.push_back({'D', 500});
        roman.push_back({'M', 1000});

        int prev = 2000;
        int sum = 0;
        

        for (char c : s) {
            // cout << c << endl;
            for(auto x : roman) {
                if(x.first == c) {
                    // cout << x.second << endl;
                    sum += x.second;                    
                    if(prev < x.second) {
                        sum = sum - prev - prev;
                        cout << sum << endl;
                    }
                    prev = x.second;

                }
            }


        }

        return sum;
        
    }
};