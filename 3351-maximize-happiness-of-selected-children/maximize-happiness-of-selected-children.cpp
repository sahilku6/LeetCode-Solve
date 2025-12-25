class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long val = happiness[i] - i;
            if (val > 0)
                ans += val;
        }
        return ans;
    }
};
