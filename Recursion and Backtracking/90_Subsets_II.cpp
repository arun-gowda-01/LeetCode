// LeetCode 90
// Subsets II

class Solution {
public:
    void solve(int start, vector<int>& nums, vector<int>& subset,
               vector<vector<int>>& ans) {
        ans.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);
            solve(i + 1, nums, subset, ans);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        solve(0, nums, subset, ans);

        return ans;
    }
};
