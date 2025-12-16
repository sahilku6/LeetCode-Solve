class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutive = 0;
        int tempCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                tempCount++;
            else {
                maxConsecutive = max(maxConsecutive, tempCount);
                tempCount = 0;
            }
        }
        maxConsecutive = max(maxConsecutive, tempCount);
        return maxConsecutive;
    }
};