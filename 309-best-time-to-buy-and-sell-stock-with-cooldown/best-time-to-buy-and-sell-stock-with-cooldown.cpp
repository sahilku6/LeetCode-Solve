class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }
    int solve(vector<int>& prices, int day, int buy, vector<vector<int>>& dp) {
        if (day >= prices.size())
            return 0;
        if (dp[day][buy] != -1)
            return dp[day][buy];
        int profit = 0;
        if (buy) { // buy section
            int take = solve(prices, day + 1, false, dp) - prices[day];
            int not_take = solve(prices, day + 1, true, dp);
            profit = max({profit, take, not_take});
        } else { // sell section
            int sell = prices[day] + solve(prices, day + 2, true, dp);
            int not_sell = solve(prices, day + 1, false, dp);
            profit = max({profit, sell, not_sell});
        }
        return dp[day][buy] = profit;
    }
};