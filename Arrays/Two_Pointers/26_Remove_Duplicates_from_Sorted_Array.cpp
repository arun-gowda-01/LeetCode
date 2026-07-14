// LeetCode 26
// Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;

        int k = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k]) {
                k++;
                nums[k] = nums[i];
            }
        }

        return k + 1;
    }
};
