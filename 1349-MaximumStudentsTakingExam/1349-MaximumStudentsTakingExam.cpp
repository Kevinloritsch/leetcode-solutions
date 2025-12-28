// Last updated: 12/27/2025, 3:44:22 PM
class Solution {
public:

    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        // min size is 1, safe to access 0
        int n = seats[0].size();

        vector<int> valid(m, -1);
        for(int i = 0; i < m; ++i) {
            int prepareMask = 0;
            for(int j = 0; j < n; ++j) {
                // left shift
                prepareMask = prepareMask * 2;
                // add 1 or 0, depending on if space is available
                prepareMask += seats[i][j] == '.';
            }
            valid[i] = prepareMask;
        }

        // m+1 rows, gives us one extra as corner condition for dp
        // 1 << n = 2^n... every possible bit mask per row
        vector<vector<int>> f(m+1, vector<int>(1 << n, -1));

        // row 0 will always be valid... nobody sits there !
        f[0][0] = 0;

        // row 0 is our temp state that doens't actually exist
        for(int i = 1; i <= m; ++i) {
            int currRow = valid[i - 1];

            for(int j = 0; j < (1 << n); ++j) {
                // j & currRow == j
                // this means that every bit in j is also in currRow
                // j & j >> 1 means we right shift j once and and it to j. it will result in a number that has a 1 for every spot that has two adjacent seats
                // !'ing that will return 0, unless every single bit is a 0. this is a check of are there adjacent seats, and only true if there arent
                if(((j & currRow) == j) && (!(j & (j >> 1)))) {
                    // we want to try every seating pattern that could work for the row above
                    for (int k = 0; k < (1 << n); ++k) {
                        // !(j & (k >> 1))
                        // the row above has no adjacent (on the right)
                        // # # .
                        // # . # is bad
                        // !((j >> 1) & k)
                        // the row above has no adjacent (on the left)
                        // . # #
                        // # . # is bad
                        // f[i - 1][k] != -1
                        // we haven't already found this row to be invalid :D
                        if (!(j & (k >> 1)) && !((j >> 1) & k) && f[i - 1][k] != -1) {

                            // best between what it already is (default - 1), or using this alternative row above it, and counting the number of students in this potential subset of j
                            f[i][j] = max(f[i][j], f[i - 1][k] + __builtin_popcount(j));
                        }
                    }
                }
            }
        }

        // in each row we've been grabbing the best number of students so far
        // so in the mth row, we have the best number of students for each bit mask possibility
        // so lets go through and grab them
        int ans = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            ans = max(ans, f[m][mask]);
        }
        return ans;
    }

    /*

    Why is this reasonable? We know we're bounded by 8 rows.
    This means, that there are 2^8 valid combinations of bits per row.
    So we then have 2^8 * 8 possible states. Then for each of those,
    we check 2^8 things. That's 5e5 total, in the worst case.
    */

};