// LeetCode 77
// Combinations

class Solution {
public:
    void solve(int start, int n, int k, vector<int>& combinations,
               vector<vector<int>>& ans) {
        if (combinations.size() == k) {
            ans.push_back(combinations);
            return;
        }

        for (int i = start; i <= n; i++) {
            combinations.push_back(i);
            solve(i + 1, n, k, combinations, ans);
            combinations.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> combinations;
        vector<vector<int>> ans;

        solve(1, n, k, combinations, ans);

        return ans;
    }
};
