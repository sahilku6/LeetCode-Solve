class Solution {
public:
    int move(vector<int>& nums, int idx) {
        int n = nums.size();
        int step = nums[idx];

        int newIdx = ((idx + step) % n + n) % n;

        return nums[newIdx];
    }

    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result.push_back(0);
            } else {
                result.push_back(move(nums, i));
            }
        }
        return result;
    }
};
