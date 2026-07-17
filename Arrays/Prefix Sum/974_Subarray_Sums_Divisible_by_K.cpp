// LeetCode 974
// Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int count = 0, currSum = 0, remainder = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            remainder = (currSum % k + k) % k;

            if (mp.find(remainder) != mp.end()) {
                count += mp[remainder];
            }

            mp[remainder]++;
        }

        return count;
    }
};
