class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                continue;
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];
                int k = binary_search(nums, j + 1, n - 1, sum);
                if (k != -1)
                    count += (k - j);
            }
        }
        return count;
    }

private:
    int binary_search(vector<int>& nums, int l, int r, int target) {
        int k = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                k = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return k;
    }
};