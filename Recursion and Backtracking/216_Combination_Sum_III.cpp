// LeetCode 216
// Combination Sum III

class Solution {
public:
    void solve(int start, int k, int target, vector<int>& combinations,
               vector<vector<int>>& ans) {
        if (target == 0 && combinations.size() == k) {
            ans.push_back(combinations);
            return;
        }

        if (target < 0)
            return;

        if (combinations.size() > k)
            return;

        for (int i = start; i <= 9; i++) {
            combinations.push_back(i);
            solve(i + 1, k, target - i, combinations, ans);
            combinations.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combinations;
        vector<vector<int>> ans;

        solve(1, k, n, combinations, ans);

        return ans;
    }
};
