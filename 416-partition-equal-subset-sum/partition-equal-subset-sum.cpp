class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));

        return helper(0, target, nums, memo);
    }

    bool helper(int index, int target, vector<int>& nums,
                vector<vector<int>>& memo) {
        if (target == 0)
            return true;

        if (index >= nums.size() || target < 0)
            return false;

        if (memo[index][target] != -1)
            return memo[index][target];

        // Option 1: Include nums[index]
        bool include = helper(index + 1, target - nums[index], nums, memo);

        // Option 2: Exclude nums[index]
        bool exclude = helper(index + 1, target, nums, memo);

        return memo[index][target] = include || exclude;
    }
};
