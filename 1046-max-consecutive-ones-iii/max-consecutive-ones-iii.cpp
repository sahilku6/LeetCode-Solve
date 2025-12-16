class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // think like to find a longest substring atmost zeros

        int left = 0;
        int right = 0;
        int maxConsecutive = 0;
        int noOfZeros = 0;
        while (right < nums.size()) {

            if (nums[right] == 0)
                noOfZeros++;

            if (noOfZeros > k) {
                if (nums[left] == 0) {
                    noOfZeros--;
                }
                left++;
            }

            if (noOfZeros <= k) {
                maxConsecutive = max(maxConsecutive, right - left + 1);
            }
            right++;
        }
        return maxConsecutive;
    }
};