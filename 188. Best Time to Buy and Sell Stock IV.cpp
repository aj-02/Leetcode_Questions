// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

// Constraints:

// 1 <= k <= 100
// 1 <= prices.length <= 1000
// 0 <= prices[i] <= 1000



class Solution {
public:
	int dp[1002][102][2];

    int maxProfit(int k, vector<int>& prices) {
		auto maximize = [&](int &x, int  y) {
			if (x < y) {
				x = y;
				return true;
			}
			return false;
		};

    	int n = prices.size();		
		const int INF = 1e9 + 1;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
				dp[i][j][0] = dp[i][j][1] = -INF;
		dp[0][0][0] = 0; dp[0][1][1] = -prices[0];

		for (int i = 0; i + 1 < n; i++)
			for (int j = 0; j <= k; j++) {
				maximize(dp[i + 1][j][0], dp[i][j][0]);		
				maximize(dp[i + 1][j][1], dp[i][j][1]);
				maximize(dp[i + 1][j + 1][1], dp[i][j][0] - prices[i + 1]);
				maximize(dp[i + 1][j][0], dp[i][j][1] + prices[i + 1]);
			}

		int ans = 0;
		for (int i = 0; i <= k; i++) maximize(ans, dp[n - 1][i][0]);
		return ans;	
    }
};
