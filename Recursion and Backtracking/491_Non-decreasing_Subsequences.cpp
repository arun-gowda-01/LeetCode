// LeetCode 491
// Non-decreasing Subsequences

class Solution {
public:
    void solve(int start, vector<int>& nums, vector<int>& sequence,
               vector<vector<int>>& ans) {
        unordered_set<int> used;

        if (sequence.size() >= 2) {
            ans.push_back(sequence);
        }

        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            if (sequence.empty() || nums[i] >= sequence.back()) {
                sequence.push_back(nums[i]);
                solve(i + 1, nums, sequence, ans);
                sequence.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> sequence;
        vector<vector<int>> ans;

        solve(0, nums, sequence, ans);

        return ans;
    }
};
