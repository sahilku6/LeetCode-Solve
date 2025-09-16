class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, nums.size(), 0);
    }
    int solve(vector<int>& nums, int target, int n, int idx) {
        if (idx == n && target == 0)
            return 1;
            
        if (idx >= n)
            return 0;

        int plus = solve(nums, target + nums[idx], n, idx + 1);
        int minus = solve(nums, target - nums[idx], n, idx + 1);

        return plus + minus;
    }
};