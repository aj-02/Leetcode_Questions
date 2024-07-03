Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
    
    for (char c : s) {
        counts[c]++;
    }
    
    int length = 0;
    bool hasOdd = false;
    
    for (auto& pair : counts) {
        int count = pair.second;
        length += (count / 2) * 2;
        if (count % 2 == 1) {
            hasOdd = true;
        }
    }
    
    if (hasOdd) {
        length += 1;
    }
    
    return length;
    }
};
