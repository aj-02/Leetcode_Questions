// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

// Constraints:

// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.


class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = ""; s += num[0];

        for(int i=1;i<num.length();++i) {
            if(k > 0 && s.length() > 0 && num[i] < s[s.length()-1]) {
                s.pop_back();
                k--;
                i--;
                continue;
            }
            else
            s += num[i];
        }
        while(k > 0 && s.length() > 0) {
            s.pop_back();
            k--;
        }

        while(s[0] == '0') {
            s.erase(s.begin());
        }
        
        if(s.length() == 0) s = "0"; 
        return s;
        
    }
};