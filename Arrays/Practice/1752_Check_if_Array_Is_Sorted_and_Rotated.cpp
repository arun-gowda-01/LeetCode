// LeetCode 1752
// Check if Array Is Sorted and Rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int next = (i + 1) % nums.size();

            if (nums[i] > nums[next])
                count++;
        }

        return count <= 1;
    }
};
