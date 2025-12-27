// Last updated: 12/27/2025, 3:45:27 PM
class Solution {
public:
    int divide(int dividend, int divisor) {

        if(divisor == 1) return dividend;
        if(divisor == -1) {
            if(dividend == -2147483648) dividend++;
            return -dividend;
        }

        long counter = 0;
        long divisorCopy = divisor;
        long dividendCopy = dividend;
        if(divisorCopy < 0) divisorCopy *= -1;
        
        if(dividendCopy < 0) {
            dividendCopy *= -1;

        }
        cout << dividendCopy << " " << divisor << endl;
        while(dividendCopy > 0) {
            dividendCopy -= divisorCopy;
            if(dividendCopy >= 0) counter ++;
        }

        cout << counter << endl;
        if(divisor < 0) counter *= -1;
        if(dividend < 0) counter *= -1;
        if(counter >= 2147483648) {
            counter = 2147483648 - 1;
        }
        if(counter < -2147483648 - 1) {
            counter = -2147483648;
        }

        

        return counter;
        
    }
};