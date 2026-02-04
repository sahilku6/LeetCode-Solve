class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4)
            return false;

        int i = 0;

        // first increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if (i == 0)
            return false; // no increase

        // decreasing
        int decStart = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        if (i == decStart)
            return false; // no decrease

        // second increasing
        int inc2Start = i;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if (i == inc2Start)
            return false; // no second increase

        // must consume entire array
        return i == n - 1;
    }
};
