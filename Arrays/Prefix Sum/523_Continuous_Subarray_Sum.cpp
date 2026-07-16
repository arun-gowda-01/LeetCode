// LeetCode 523
// Continuous Subarray Sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int currSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            if (mp.find(currSum % k) != mp.end()) {
                if (i - mp[currSum % k] >= 2)
                    return true;
            } else {
                mp[currSum % k] = i;
            }
        }

        return false;
    }
};
