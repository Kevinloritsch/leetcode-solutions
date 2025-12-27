// Last updated: 12/27/2025, 3:44:51 PM
class Solution {
public:
    int bulbSwitch(int n) {

        // if perfect square, return that
        // else drop the decimal

        return int(sqrt(n));        
    }
};

// simulate n^2
// modulo for n

// y y y y y
// y n y n y
// y n n n y
// y n n y y
// y n n y y



// 1 2 3 4 5 6 7 8 9 10
// y y y y y y y y y  y
// y n y n y n y n y  n
// y n n n y y y n n  n
// y n n y y y y y n  n
// y n n y n y y y n  y
// y n n y n n y y n  y
// y n n y n n n y n  y
// y n n y n n n n n  y
// y n n y n n n n y  y
// y n n y n n n n y  n

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// y y y y y y y y y  y  y  y  y  y  y  y 1
// y n y n y n y n y  n  y  n  y  n  y  n 2
// y n n n y y y n n  n  y  y  y  n  n  n 3
// y n n y y y y y n  n  y  n  y  n  n  y 4
// y n n y n y y y n  y  y  n  y  n  y  y 5
// y n n y n n y y n  y  y  y  y  n  y  y 6
// y n n y n n n y n  y  y  y  y  y  y  y 7
// y n n y n n n n n  y  y  y  y  y  y  n 8
// y n n y n n n n y  y  y  y  y  y  y  n 9
// y n n y n n n n y  n  y  y  y  y  y  n 10
// y n n y n n n n y  n  n  y  y  y  y  n 11
// y n n y n n n n y  n  n  n  y  y  y  n 12
// y n n y n n n n y  n  n  n  n  y  y  n 13
// y n n y n n n n y  n  n  n  n  n  y  n 14
// y n n y n n n n y  n  n  n  n  n  n  n 15
// y n n y n n n n y  n  n  n  n  n  n  y 16