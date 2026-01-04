class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            int count = 0;
            int tempSum = 0;
            for (int i = 1; i <= num; i++) {
                if (num % i == 0) {
                    tempSum += i;
                    if (count > 4) {
                        count = 0;
                        break;
                    }
                    count++;
                }
            }
            if (count == 4)
                sum += tempSum;
        }
        return sum;
    }
};