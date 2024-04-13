// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.


#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> stk;
        
        for (int i = 0; i <= heights.size(); ++i) {
            while (!stk.empty() && (i == heights.size() || heights[stk.top()] > heights[i])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                ans = max(ans, h * w);
            }
            stk.push(i);
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        
        int ans = 0;
        vector<int> hist(matrix[0].size(), 0);
        
        for (auto& row : matrix) {
            for (int i = 0; i < row.size(); ++i)
                hist[i] = row[i] == '0' ? 0 : hist[i] + 1;
            ans = max(ans, largestRectangleArea(hist));
        }
        
        return ans;
    }
};