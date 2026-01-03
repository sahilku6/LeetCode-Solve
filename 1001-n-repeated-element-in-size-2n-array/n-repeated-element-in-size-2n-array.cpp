class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int,int> mp;

        for (int x : nums) {
            mp[x]++;
            if (mp[x] > 1) {
                return x;
            }
        }
        return -1;
    }
};
