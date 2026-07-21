// LeetCode 1249
// Minimum Remove to Make Valid Parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp;
        int open = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
                temp.push_back(c);
            } else if (c == ')') {
                if (open > 0) {
                    open--;
                    temp.push_back(c);
                }
            } else {
                temp.push_back(c);
            }
        }

        string res;

        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == '(' && open > 0) {
                open--;
                continue;
            }

            res.push_back(temp[i]);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
