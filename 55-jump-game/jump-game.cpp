class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, nums.size(), 0,dp);
    }

    bool solve(vector<int>& nums, int n, int idx, vector<int>& dp) {
        if (idx == n - 1)
            return true;
        if (idx >= n)
            return false;
        if (dp[idx] != -1)
            return dp[idx];
        for (int i = 1; i <= nums[idx]; i++) {
            if (solve(nums, n, idx + i, dp) == true)
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
};