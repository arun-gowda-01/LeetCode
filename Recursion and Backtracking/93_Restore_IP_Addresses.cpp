// LeetCode 93
// Restore IP Addresses

class Solution {
public:
    void solve(int index, string& s, vector<string>& parts, vector<string>& ans) {
        if (parts.size() == 4) {
            if (index == s.size()) {
                string ip = parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3];
                ans.push_back(ip);
            }
            return;
        }

        for (int i = index; i < s.size() && i < index + 3; i++) {
            if (i > index && s[index] == '0')
                break;

            string part = s.substr(index, i - index + 1);

            if (stoi(part) > 255)
                break;

            parts.push_back(part);
            solve(i + 1, s, parts, ans);
            parts.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> parts;
        vector<string> ans;

        solve(0, s, parts, ans);

        return ans;
    }
};
