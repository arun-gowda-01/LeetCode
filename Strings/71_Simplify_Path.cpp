// LeetCode 71
// Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (curr == "" || curr == ".") {
                    // Ignore empty strings and current directory
                } else if (curr == "..") {
                    if (!st.empty())
                        st.pop_back();
                } else {
                    st.push_back(curr);
                }

                curr = "";
            } else {
                curr += path[i];
            }
        }

        string result = "";

        for (string dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};
