// LeetCode 22
// Generate Parentheses

class Solution {
public:
    void solve(int n, string& current, int open, int close, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            solve(n, current, open + 1, close, ans);
            current.pop_back();
        }

        if (close < n && close < open) {
            current.push_back(')');
            solve(n, current, open, close + 1, ans);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string current;
        vector<string> ans;

        solve(n, current, 0, 0, ans);

        return ans;
    }
};
