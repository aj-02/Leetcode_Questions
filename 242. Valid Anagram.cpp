// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0; i<s.length(); i++){
            if(s[i] != t[i]){
                return false;
            }
        }

        return true;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        
        if(s.length() != t.length()){
            return false;
        }
        
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        for(int i=0; i<t.size(); i++){
            mp[t[i]]--;
        }

        for(auto i: mp){
            if(i.second != 0){
                return false;
            }
        }

        return true;

        
    }
};