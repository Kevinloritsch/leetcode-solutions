// Last updated: 12/27/2025, 3:44:31 PM
class Solution {
public:
    int smallestRepunitDivByK(const int& k) {

        if(k % 2 == 0 || k % 5 == 0) return -1;

        long test = 1;
        int i = 1;

        while(true) {
            if(test % k == 0) break;
            test *= 10;
            test++;
            test = test % k;
            ++i;
        }

        return i;
        
    }
};