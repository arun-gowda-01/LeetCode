// LeetCode 1392
// Longest Happy Prefix

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size(), 0);
        int j = 0;

        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j])
                j = lps[j - 1];

            if (s[i] == s[j])
                j++;

            lps[i] = j;
        }

        int len = lps[s.size() - 1];

        return s.substr(0, len);
    }
};
