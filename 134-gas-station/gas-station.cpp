class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if (totalCost > totalGas)
            return -1;

        int resultIdx = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];

            if (total < 0) {
                resultIdx = i + 1;
                total = 0;
            }
        }
        return resultIdx;
    }
};