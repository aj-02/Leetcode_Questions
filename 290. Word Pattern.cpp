// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
 

// Constraints:

// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                words.push_back(word);
                word = "";
            }else{
                word += s[i];
            }
        }
        words.push_back(word);
        if(words.size() != pattern.length()){
            return false;
        }
        
        map<char,string> mp;
        map<string,char> str;
        for(int i=0; i<pattern.size(); i++){
            if(mp.find(pattern[i]) == mp.end() && str.find(words[i]) == str.end()){
                mp[pattern[i]] = words[i];
                str[words[i]] = pattern[i];
            }else{ 
                if(mp[pattern[i]] != words[i] || str[words[i]] != pattern[i]){
                    return false;
                }
            }    
        }

        return true;
    }
};