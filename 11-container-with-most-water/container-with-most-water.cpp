class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        while (left < right) {
            int width = right - left;
            int high = min(height[left], height[right]);
            int water = width * high;
            max_water = max(max_water, water);
            height[left] < height[right] ? left++ : right--;
        }
        return max_water;
    }
};