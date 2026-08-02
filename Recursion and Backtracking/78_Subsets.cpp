// LeetCode 78
// Subsets

class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& subset,
               vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        solve(index + 1, nums, subset, ans);

        subset.pop_back();
        solve(index + 1, nums, subset, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;

        solve(0, nums, subset, ans);

        return ans;
    }
};
