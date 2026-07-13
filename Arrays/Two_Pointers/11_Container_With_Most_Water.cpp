// LeetCode 11
// Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int ht = height[left] < height[right] ? height[left] : height[right];

            maxWater = max(maxWater, ht * width);

            height[left] < height[right] ? left++ : right--;
        }

        return maxWater;
    }
};