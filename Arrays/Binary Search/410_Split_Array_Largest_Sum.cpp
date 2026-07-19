// LeetCode 410
// Split Array Largest Sum

class Solution {
public:
    bool isValid(vector<int>& nums, int maxSum, int k) {
        int sum = 0;
        int kUsed = 1;

        for (int num : nums) {
            if (sum + num > maxSum) {
                sum = 0;
                kUsed++;
            }

            sum += num;
        }

        return kUsed <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isValid(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
