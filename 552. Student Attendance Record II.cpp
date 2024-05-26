// An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

// 'A': Absent.
// 'L': Late.
// 'P': Present.
// Any student is eligible for an attendance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

// Example 1:

// Input: n = 2
// Output: 8
// Explanation: There are 8 records with length 2 that are eligible for an award:
// "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
// Example 2:

// Input: n = 1
// Output: 3
// Example 3:

// Input: n = 10101
// Output: 183236316
 

// Constraints:

// 1 <= n <= 105


class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007;
        vector<vector<int>> dp_last(2, vector<int>(3, 0)); // previous state
        vector<vector<int>> dp_current(2, vector<int>(3, 0)); // current state

        dp_last[0][0] = 1; // empty string

        for (int i = 0; i < n; i++) {
            for (int count_a = 0; count_a < 2; count_a++) {
                for (int count_l = 0; count_l < 3; count_l++) {
                    // choose "P"
                    dp_current[count_a][0] = (dp_current[count_a][0] + dp_last[count_a][count_l]) % MOD;
                    // choose "A"
                    if (count_a == 0) {
                        dp_current[count_a + 1][0] = (dp_current[count_a + 1][0] + dp_last[count_a][count_l]) % MOD;
                    }
                    // Choose "L"
                    if (count_l < 2) {
                        dp_current[count_a][count_l + 1] = (dp_current[count_a][count_l + 1] + dp_last[count_a][count_l]) % MOD;
                    }
                }
            }
            dp_last = dp_current; // Reference current to previous
            dp_current = vector<vector<int>>(2, vector<int>(3, 0)); // make new current
        }

        // Sum up the counts for all combinations of length 'n' with different count_a and count_l.
        int res = 0;
        for (int count_a = 0; count_a < 2; count_a++) {
            for (int count_l = 0; count_l < 3; count_l++) {
                res = (res + dp_last[count_a][count_l]) % MOD;
            }
        }
        return res;
    }
};