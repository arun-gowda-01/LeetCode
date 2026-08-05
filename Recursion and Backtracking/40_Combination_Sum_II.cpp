// LeetCode 40
// Combination Sum II

class Solution {
public:
    void solve(int start, int target, vector<int>& candidates,
               vector<int>& combinations, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(combinations);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            combinations.push_back(candidates[i]);

            solve(i + 1, target - candidates[i], candidates, combinations, ans);

            combinations.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> combinations;
        vector<vector<int>> ans;

        solve(0, target, candidates, combinations, ans);

        return ans;
    }
};
