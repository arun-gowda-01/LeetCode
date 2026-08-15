// LeetCode 140
// Word Break II

class Solution {
public:
    void solve(int start, string s, vector<string>& wordDict,
               unordered_set<string>& st, string& current,
               vector<string>& ans) {
        if (start == s.size()) {
            current.pop_back();
            ans.push_back(current);
            current.push_back(' ');
            return;
        }

        for (int end = start; end < s.size(); end++) {
            string word = s.substr(start, end - start + 1);

            if (st.count(word)) {
                current += word + " ";

                solve(end + 1, s, wordDict, st, current, ans);

                current.erase(current.size() - word.size() - 1);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        string current = "";
        vector<string> ans;

        solve(0, s, wordDict, st, current, ans);

        return ans;
    }
};
