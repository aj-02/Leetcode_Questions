// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

// If the current number is even, you have to divide it by 2.

// If the current number is odd, you have to add 1 to it.

// It is guaranteed that you can always reach one for all test cases.

 

// Example 1:

// Input: s = "1101"
// Output: 6
// Explanation: "1101" corressponds to number 13 in their decimal representation.
// Step 1) 13 is odd, add 1 and obtain 14. 
// Step 2) 14 is even, divide by 2 and obtain 7.
// Step 3) 7 is odd, add 1 and obtain 8.
// Step 4) 8 is even, divide by 2 and obtain 4.  
// Step 5) 4 is even, divide by 2 and obtain 2. 
// Step 6) 2 is even, divide by 2 and obtain 1.  
// Example 2:

// Input: s = "10"
// Output: 1
// Explanation: "10" corressponds to number 2 in their decimal representation.
// Step 1) 2 is even, divide by 2 and obtain 1.  
// Example 3:

// Input: s = "1"
// Output: 0


class Solution {
public:
    int numSteps(string& s) {
        int n=s.size(), div=n-1, add1=0, carry=0, cnt1=0;
        for(int i=n-1; i>0; i--){
            while(i>0 && (s[i]-'0'+carry)&1){
                carry|=s[i]=='1';
                cnt1++;
                i--;
            }
            add1+=cnt1;
            cnt1=0;
            carry|=s[i]=='1';
        }
        return div+add1+carry;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();