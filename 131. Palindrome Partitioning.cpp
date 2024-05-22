// ---------------------------
// Error
// ---------------------------
// The drive or UNC share you selected does not exist or is not accessible. Please select another.
// ---------------------------
// OK   
// ---------------------------



class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        int lenS = s.length();

        function<void(int)> explore = [&](int index) {
            if (index >= lenS) {
                result.push_back(curr);
                return;
            }

            for (int i = index; i < lenS; ++i) {
                string subStr = s.substr(index, i - index + 1);
                if (isPalindrome(subStr)) {
                    curr.push_back(subStr);
                    explore(i + 1);
                    curr.pop_back();
                }
            }
        };

        explore(0);
        return result;
    }

private:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};