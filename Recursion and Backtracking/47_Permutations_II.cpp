// LeetCode 47
// Permutations II

class Solution {
public:
    void solve(vector<int>& nums, vector<int>& permutations,
               vector<vector<int>>& ans, vector<bool>& used) {
        if (permutations.size() == nums.size()) {
            ans.push_back(permutations);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            permutations.push_back(nums[i]);

            solve(nums, permutations, ans, used);

            permutations.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> permutations;
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);

        solve(nums, permutations, ans, used);

        return ans;
    }
};
