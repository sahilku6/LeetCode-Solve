class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<int> pq;

        for (auto [first, second] : freq) {
            pq.push(second);
        }
        int first = pq.top();
        int sum = first;
        pq.pop();
        while (!pq.empty()) {
            if (first == pq.top()) {
                first = pq.top();
                sum += first;
                pq.pop();
            } else {
                break;
            }
        }
        return sum;
    }
};