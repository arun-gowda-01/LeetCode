// LeetCode 1415
// The k-th Lexicographical String of All Happy Strings of Length n

class Solution {
public:
    void solve(int n, int& k, string& current, string& ans) {
        if (current.size() == n) {
            k--;

            if (k == 0)
                ans = current;

            return;
        }

        for (char c = 'a'; c <= 'c'; c++) {
            if (!current.empty() && current.back() == c)
                continue;

            current.push_back(c);
            solve(n, k, current, ans);
            current.pop_back();

            if (!ans.empty())
                return;
        }
    }

    string getHappyString(int n, int k) {
        string current;
        string ans;

        solve(n, k, current, ans);

        return ans;
    }
};
