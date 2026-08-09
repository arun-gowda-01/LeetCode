// LeetCode 784
// Letter Case Permutation

class Solution {
public:
    void solve(int index, string& s, vector<string>& ans, string& permutation) {
        if (index == s.size()) {
            ans.push_back(permutation);
            return;
        }

        if (isalpha(s[index])) {
            permutation.push_back(tolower(s[index]));
            solve(index + 1, s, ans, permutation);
            permutation.pop_back();

            permutation.push_back(toupper(s[index]));
            solve(index + 1, s, ans, permutation);
            permutation.pop_back();
        }
        else {
            permutation.push_back(s[index]);
            solve(index + 1, s, ans, permutation);
            permutation.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string permutation;

        solve(0, s, ans, permutation);

        return ans;
    }
};
