// LeetCode 17
// Letter Combinations of a Phone Number

class Solution {
public:
    void solve(int index, string& digits, string& current,
               vector<string>& ans, vector<string>& mapping) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters) {
            current.push_back(c);
            solve(index + 1, digits, current, ans, mapping);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string current = "";

        solve(0, digits, current, ans, mapping);

        return ans;
    }
};
