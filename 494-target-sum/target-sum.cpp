class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> dp;
        return solve(nums, target, n, 0, dp);
    }
    int solve(vector<int>& nums, int target, int n, int idx,
              unordered_map<string, int>& dp) {
        if (idx == n && target == 0)
            return 1;

        if (idx >= n)
            return 0;

        string key = to_string(idx) + "_" + to_string(target);

        if (dp.count(key))
            return dp[key];

        int plus = solve(nums, target + nums[idx], n, idx + 1, dp);
        int minus = solve(nums, target - nums[idx], n, idx + 1, dp);

        return dp[key] = plus + minus;
    }
};