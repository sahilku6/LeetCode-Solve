class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        int count = 0;
        for (auto num : freq) {
            if (num.second == maxFreq) count++;
        }

        return count * maxFreq;
    }
};
