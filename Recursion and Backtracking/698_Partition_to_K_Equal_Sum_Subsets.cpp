// LeetCode 698
// Partition to K Equal Sum Subsets

class Solution {
public:
    bool solve(int start, vector<int>& nums, int currSum, int kRemaining,
               int target, vector<bool>& visited) {
        if (kRemaining == 1)
            return true;

        if (currSum == target) {
            return solve(0, nums, 0, kRemaining - 1, target, visited);
        }

        for (int i = start; i < nums.size(); i++) {
            if (visited[i])
                continue;

            if (currSum + nums[i] > target)
                continue;

            visited[i] = true;

            if (solve(i + 1, nums, currSum + nums[i], kRemaining, target, visited))
                return true;

            visited[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % k != 0)
            return false;

        int target = totalSum / k;

        sort(nums.rbegin(), nums.rend());

        vector<bool> visited(nums.size(), false);

        return solve(0, nums, 0, k, target, visited);
    }
};
