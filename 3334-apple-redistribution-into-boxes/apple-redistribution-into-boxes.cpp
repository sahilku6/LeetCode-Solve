class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        
        int appleSum = 0;
        for (int num : apple) {
            appleSum += num;
        }
        
        int boxCount = 0;
        int i = 0;
        while (appleSum > 0) {
            appleSum -= capacity[i];
            i++;
            boxCount++;
        }
        
        return boxCount;
    }
};