// LeetCode 131
// Palindrome Partitioning

class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int start, string& s, vector<string>& current,
               vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                solve(end + 1, s, current, ans);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> ans;

        solve(0, s, current, ans);

        return ans;
    }
};
