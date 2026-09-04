// LeetCode 169
// Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0)
                maj = num;

            if (num == maj)
                count++;
            else
                count--;
        }

        return maj;
    }
};
