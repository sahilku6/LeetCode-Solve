class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost = nums[0];
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (firstMin > nums[i]) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else if (secondMin > nums[i]) {
                secondMin = nums[i];
            }
        }
        return (cost + firstMin + secondMin);
    }
};