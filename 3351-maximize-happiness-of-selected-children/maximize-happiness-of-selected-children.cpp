class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long minusPoint = 0;
        long long maxHappinessSum = 0;
        long long i = 0;
        while (k > 0) {
            long long temp = happiness[i] - minusPoint;
            if (temp >= 0)
                maxHappinessSum += temp;
            else
                maxHappinessSum += 0;
            i++;
            k--;
            minusPoint++;
        }
        return maxHappinessSum;
    }
};